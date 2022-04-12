# This Python file uses the following encoding: utf-8
import os
import sys

from PySide6.QtWidgets import QApplication, QMainWindow
from PySide6.QtCore import QFile
from PySide6.QtUiTools import QUiLoader


class MainWindow(QMainWindow):
    def __init__(self):
        super(MainWindow, self).__init__()
        self.load_ui()

    def load_ui(self):
        loader = QUiLoader()
        ui_file = QFile("form.ui")
        ui_file.open(QFile.ReadOnly)
        loader.load(ui_file, self)
        ui_file.close()


if __name__ == "__main__":
    app = QApplication([])
    widget = MainWindow()
    widget.show()
    sys.exit(app.exec())
