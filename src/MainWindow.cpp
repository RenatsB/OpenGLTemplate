#include "MainWindow.h"


void MainWindow::init(const std::shared_ptr<Scene> &io_scene)
{

  m_scene = io_scene;
  m_ui.setupUi(this);
  m_ui.s_mainWindowGridLayout->addWidget(m_scene.get(),0,0,3,5);
  //QSignalMapper *mapper = new QSignalMapper(this; mapper->seMapping(m_ui.loadGeo, ));
  connect(m_ui.m_rotating, SIGNAL(clicked(bool)),m_scene.get(), SLOT(rotating(bool)));
  connect(m_ui.select, SIGNAL( clicked(bool)), m_scene.get(), SLOT(select()));
  connect(m_ui.deselect, SIGNAL( clicked(bool)), m_scene.get(), SLOT(deselect()));
  connect(m_ui.loadGeoInput, SIGNAL( textEdited(QString)), m_scene.get(), SLOT(receiveGeoPath(QString)));
  connect(m_ui.loadGeo, SIGNAL( clicked(bool)), m_scene.get(), SLOT(loadGeo()));
  connect(m_ui.tableWidget, SIGNAL( itemChanged(QTableWidgetItem*)), m_scene.get(), SLOT(receiveTableInfo(QTableWidgetItem*)));
}

//----------------------------------------------------------------------------------------------------------------------

void MainWindow::keyPressEvent(QKeyEvent *io_event)
{
  // this method is called every time the main window recives a key event.
  // we then switch on the key value and set the camera in the GLWindow
  switch ( io_event->key() )
  {
    case Qt::Key_Escape : QApplication::exit(EXIT_SUCCESS); break;
    default : break;
  }
  m_scene->keyPress(io_event);
}

//----------------------------------------------------------------------------------------------------------------------

void MainWindow::mouseMoveEvent(QMouseEvent * io_event)
{
  m_scene->mouseMove(io_event);
}

//----------------------------------------------------------------------------------------------------------------------

void MainWindow::mousePressEvent(QMouseEvent * io_event)
{
  m_scene->mouseClick(io_event);
}

//----------------------------------------------------------------------------------------------------------------------

void MainWindow::mouseReleaseEvent(QMouseEvent * io_event)
{
  m_scene->mouseClick(io_event);
}

//----------------------------------------------------------------------------------------------------------------------
