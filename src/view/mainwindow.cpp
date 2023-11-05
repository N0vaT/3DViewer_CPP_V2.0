#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(s21::ViewerController viewerController,
                       s21::Settings *settings, QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      viewerController(viewerController),
      settings(settings) {
  ui->setupUi(this);
  timer = new QTimer(this);
  glwidget = new GLWidget();
  attach(glwidget);
  viewerController.readSettings();
  glwidget->setSettings(settings);
  ui->openGLWidget->setLayout(new QHBoxLayout());
  ui->openGLWidget->layout()->addWidget(glwidget);

  connect(ui->rotateXLeftButton, &QPushButton::clicked, this,
          &MainWindow::rotate);
  connect(ui->rotateXRightButton, &QPushButton::clicked, this,
          &MainWindow::rotate);
  connect(ui->rotateYLeftButton, &QPushButton::clicked, this,
          &MainWindow::rotate);

  connect(ui->rotateYRightButton, &QPushButton::clicked, this,
          &MainWindow::rotate);
  connect(ui->rotateZLeftButton, &QPushButton::clicked, this,
          &MainWindow::rotate);
  connect(ui->rotateZRightButton, &QPushButton::clicked, this,
          &MainWindow::rotate);

  connect(ui->moveXLeftButton, &QPushButton::clicked, this, &MainWindow::move);
  connect(ui->moveYLeftButton, &QPushButton::clicked, this, &MainWindow::move);
  connect(ui->moveZLeftButton, &QPushButton::clicked, this, &MainWindow::move);
  connect(ui->moveXRightButton, &QPushButton::clicked, this, &MainWindow::move);
  connect(ui->moveYRightButton, &QPushButton::clicked, this, &MainWindow::move);
  connect(ui->moveZRightButton, &QPushButton::clicked, this, &MainWindow::move);

  connect(ui->shrinkButton, &QPushButton::clicked, this, &MainWindow::scale);
  connect(ui->enlargeButton, &QPushButton::clicked, this, &MainWindow::scale);

  connect(ui->dotColorButton, &QPushButton::clicked, this,
          &MainWindow::chooseColor);
  connect(ui->lineColorButton, &QPushButton::clicked, this,
          &MainWindow::chooseColor);
  connect(ui->backColorButton, &QPushButton::clicked, this,
          &MainWindow::chooseColor);
  connect(ui->openFileButton, &QPushButton::pressed, this,
          &MainWindow::openFile);
  connect(ui->screenshotButton, &QPushButton::clicked, this,
          &MainWindow::takeScreenshot);
  connect(ui->recordGifButton, &QPushButton::clicked, this,
          &MainWindow::recordGIF);

  ui->rotateSpinBox->setValue(3.1415 / 10);
  ui->moveSpinBox->setValue(0.25);
  ui->scaleSpinBox->setValue(1.1);

  ui->projecttionComboBox->addItem("Parallel");
  ui->projecttionComboBox->addItem("Central");

  ui->dotTypeComboBox->addItem("Circle");
  ui->dotTypeComboBox->addItem("Square");
  ui->dotTypeComboBox->addItem("None");

  ui->lineTypeComboBox->addItem("Solid");
  ui->lineTypeComboBox->addItem("Dashed");
  ui->lineTypeComboBox->addItem("None");

  connect(ui->applySettingButton, &QPushButton::clicked, this,
          &MainWindow::applySettings);
  dotColorFlag = false;
  lineColorFlag = false;
  backColorFlag = false;
}

MainWindow::~MainWindow() {
  if (timer != NULL) delete timer;
  if (glwidget != NULL) delete glwidget;
  screens.clear();
  delete ui;
}

void MainWindow::openFile() {
  QString string = QFileDialog::getOpenFileName(this, tr("Open file"), "/Users",
                                                tr("Object file (*.obj)"));
  std::string filePath = string.toStdString();
  try {
    object = viewerController.initObject(filePath);
    ui->label_fileName->setText(string);
    ui->label_numberVertices->setText(
        QString::number(object.getVerticesNumber()));
    ui->label_numberPolygons->setText(
        QString::number(object.getPolygonsNumber()));
    ui->errorDescription->setText("SUCCESS");
    glwidget->setObject(&object);
    glwidget->maxV = object.getMaxVertex();
    glwidget->minV = object.getMinVertex();
    glwidget->paintGL();
    glwidget->update();
  } catch (const std::exception &e) {
    ui->errorDescription->setText(e.what());
  }
}

void MainWindow::rotate() {
  bool isLeft = (sender() == ui->rotateXLeftButton) ||
                (sender() == ui->rotateYLeftButton) ||
                (sender() == ui->rotateZLeftButton);
  double angle = ui->rotateSpinBox->value() * (isLeft ? 1 : -1);

  try {
    s21::Vertex midPoint = viewerController.middlePoint(&object);
    viewerController.moveObject(&object, -midPoint.x, -midPoint.y, -midPoint.z);
    if (sender() == ui->rotateXLeftButton ||
        sender() == ui->rotateXRightButton) {
      viewerController.rotateObjectX(&object, angle);
    } else if (sender() == ui->rotateYLeftButton ||
               sender() == ui->rotateYRightButton) {
      viewerController.rotateObjectY(&object, angle);
    } else {
      viewerController.rotateObjectZ(&object, angle);
    }
    viewerController.moveObject(&object, midPoint.x, midPoint.y, midPoint.z);
    glwidget->paintGL();
    glwidget->update();
  } catch (const std::exception &e) {
    ui->errorDescription->setText(e.what());
  }
}

void MainWindow::move() {
  bool isLeft = (sender() == ui->moveXLeftButton) ||
                (sender() == ui->moveYLeftButton) ||
                (sender() == ui->moveZLeftButton);
  double shift = ui->moveSpinBox->value() * (isLeft ? 1 : -1);

  try {
    if (sender() == ui->moveXLeftButton || sender() == ui->moveXRightButton) {
      viewerController.moveObject(&object, shift, 0, 0);
    } else if (sender() == ui->moveYLeftButton ||
               sender() == ui->moveYRightButton) {
      viewerController.moveObject(&object, 0, shift, 0);
    } else {
      viewerController.moveObject(&object, 0, 0, shift);
    }
    glwidget->paintGL();
    glwidget->update();
  } catch (const std::exception &e) {
    ui->errorDescription->setText(e.what());
  }
}

void MainWindow::scale() {
  double scale = ui->scaleSpinBox->value();

  if (sender() == ui->shrinkButton) scale = 1 / scale;

  try {
    viewerController.scaleObject(&object, scale, scale, scale);
    glwidget->paintGL();
    glwidget->update();
  } catch (const std::exception &e) {
    ui->errorDescription->setText(e.what());
  }
}

void MainWindow::applySettings() {
  if (dotColorFlag) {
    settings->setDotColor(dotColor.red() / 255.0, dotColor.green() / 255.0,
                          dotColor.blue() / 255.0);
  }
  if (lineColorFlag) {
    settings->setLineColor(lineColor.red() / 255.0, lineColor.green() / 255.0,
                           lineColor.blue() / 255.0);
  }
  if (backColorFlag) {
    settings->setBackColor(backColor.red() / 255.0, backColor.green() / 255.0,
                           backColor.blue() / 255.0);
  }
  settings->setLineSize(ui->lineSizeSpinBox->value());
  settings->setDotSize(ui->dotSizeSpinBox->value());

  if (ui->projecttionComboBox->currentIndex() == 1) {
    settings->setProjectionType(2);
  } else {
    settings->setProjectionType(1);
  }

  if (ui->dotTypeComboBox->currentIndex() == 0) {
    settings->setDotType(0);
  } else if (ui->dotTypeComboBox->currentIndex() == 1) {
    settings->setDotType(1);
  } else if (ui->dotTypeComboBox->currentIndex() == 2) {
    settings->setDotType(2);
  }

  if (ui->lineTypeComboBox->currentIndex() == 0) {
    settings->setLineType(0);
  } else if (ui->lineTypeComboBox->currentIndex() == 1) {
    settings->setLineType(1);
  } else if (ui->lineTypeComboBox->currentIndex() == 2) {
    settings->setLineType(2);
  }
  notify();
}

void MainWindow::chooseColor() {
  if (ui->dotColorButton == sender()) {
    dotColor = QColorDialog::getColor();
    dotColorFlag = true;
  } else if (ui->lineColorButton == sender()) {
    lineColor = QColorDialog::getColor();
    lineColorFlag = true;
  } else if (ui->backColorButton == sender()) {
    backColor = QColorDialog::getColor();
    backColorFlag = true;
  }
}

void MainWindow::takeScreenshot() {
  QScreen *screen = QGuiApplication::primaryScreen();
  QPixmap screenshot = screen->grabWindow(this->glwidget->winId());
  QString fileName = QFileDialog::getSaveFileName(
      this, tr("Save Screenshot"), "",
      tr("BMP Files (*.bmp);; JPEG Files (*.jpeg)"));

  if (!fileName.isEmpty()) {
    QFileInfo fileInfo(fileName);
    QString format = fileInfo.suffix().toLower();

    if (format == "bmp") {
      screenshot.save(fileName, "BMP");
    } else if (format == "jpg" || format == "jpeg") {
      screenshot.save(fileName, "JPEG");
    } else {
      ui->errorDescription->setText("WRONG FILE");
    }
  }
}

void MainWindow::recordGIF() {
  if (timer == NULL) timer = new QTimer(this);
  timer->setInterval(1000 / 10);
  connect(timer, &QTimer::timeout, this, &MainWindow::tick);
  timer->start();
  timerCounter = 0;
}

void MainWindow::tick() {
  QPixmap pixmap = glwidget->grab();
  QImage image = pixmap.toImage();
  screens.append(
      image.scaled(640, 480, Qt::KeepAspectRatio, Qt::SmoothTransformation));

  if (++timerCounter >= 5 * 10) {
    timer->stop();
    QGifImage *gif = new QGifImage();
    gif->setDefaultDelay(1000 / 10);
    for (const QImage &img : screens) {
      gif->addFrame(img);
    }
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save GIF"), "",
                                                    tr("GIF Files (*.gif)"));

    if (!fileName.isEmpty()) {
      gif->save(fileName);
    }
    screens.clear();
    delete gif;
  }
}
