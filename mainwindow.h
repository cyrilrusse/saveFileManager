#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <filesystem>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    std::filesystem::path save_name;
    std::filesystem::path elden_ring_savefile = "C:\\Users\\cyril\\AppData\\Roaming\\EldenRing";
};

#endif // MAINWINDOW_H
