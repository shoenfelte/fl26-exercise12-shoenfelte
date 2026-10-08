#include <QtTest/QtTest>
#include <QtWidgets>
#include <QDebug>

#include "toggle_widget.h"

class TestToggleWidget : public QObject {
  Q_OBJECT

private slots:

  // Define tests here
  void initialState();
  void toggleOnOff();
  void toggleMultipleClicks();
  
};

// Implement the tests here
void TestToggleWidget::initialState() {
  ToggleWidget w;
  // light starts off
  QVERIFY(!w.isOn());
}
 
void TestToggleWidget::toggleOnOff() {
  ToggleWidget w;
 
  QPushButton * pb = w.findChild<QPushButton *>();
  QVERIFY(pb != nullptr);
 
  QVERIFY(!w.isOn());
 
  // first click turn light on
  QTest::mouseClick(pb, Qt::LeftButton);
  QVERIFY(w.isOn());
 
  // second click turns it off again
  QTest::mouseClick(pb, Qt::LeftButton);
  QVERIFY(!w.isOn());
}
 
void TestToggleWidget::toggleMultipleClicks() {
  ToggleWidget w;
  QPushButton * pb = w.findChild<QPushButton *>();
  QVERIFY(pb != nullptr);
 
  for (int i = 1; i <= 6; ++i) {
    QTest::mouseClick(pb, Qt::LeftButton);
    // odd number of clicks = on, even = off
    QCOMPARE(w.isOn(), i % 2 == 1);
  }
}

QTEST_MAIN(TestToggleWidget)
#include "test_toggle_widget.moc"
