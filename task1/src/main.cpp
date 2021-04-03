#include <QApplication>
#include <QPushButton>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include "../includes/Image.h"
#include "../includes/filters.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Image originalImg{"/home/abdulla167/CLionProjects/CV/resources/lenna.png"};
    Image grayImg = Image::RGB2Gray(originalImg);
    Image edgedImg = perwitEdgeDetector(grayImg);

    QImage image(originalImg.width, originalImg.height, QImage::Format_RGB32);
    for (int j = 0; j < originalImg.height; ++j) {
        for (int i = 0; i < originalImg.width; ++i) {
            QRgb rgb = qRgb(edgedImg.data[j][i][0], edgedImg.data[j][i][0], edgedImg.data[j][i][0]);
            image.setPixel(i, j, rgb);
        }
    }
    QGraphicsScene scene;
    QGraphicsView view(&scene);
    QGraphicsPixmapItem item(QPixmap::fromImage(image));
    scene.addItem(&item);
    view.show();
    return QApplication::exec();
}
