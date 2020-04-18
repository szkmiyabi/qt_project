#include <QCoreApplication>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>

//プロトタイプ宣言
void printHTML(QString html);

//メイン関数
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString *html = new QString;
    qDebug() <<"Start";

    QNetworkAccessManager manager;
    QNetworkRequest req(QUrl("http://www.dustyfeet.com"));
    QNetworkReply* reply = manager.get(req);

    //QNetworkReply signalsに接続
    //ラムダ式によるインライン関数で処理
    /*
     * [captured variables](arguments) {
     *   lambda code
     * }
    */
    QObject::connect(reply, &QNetworkReply::readyRead,
        [reply, html](){
            html->append(QString(reply->readAll()));
        }
    );

    QObject::connect(reply, &QNetworkReply::downloadProgress,
        [reply](qint64 bytesReceived, qint64 bytesTotal) {
            qDebug() <<"Progress::" <<bytesReceived <<"bytes/" <<bytesTotal <<"bytes";
        }

    );

    QObject::connect(reply, &QNetworkReply::finished,
        [=]() {
            printHTML(*html);
        }
    );

    return a.exec();
}

//関数の実装
void printHTML(QString html)
{
    qDebug()<<"Done";
    qDebug()<<html;
}
