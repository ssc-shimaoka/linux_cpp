#include <iostream>
#include <fstream>
#include <string>

int main()
{
    const char *fileName = "/home/shimaoka/ピクチャ/data01";

    //ofstreamを読み取りモードで開き、末尾に移動
    std::ofstream ofs(fileName, std::ios::in | std::ios::ate);
    if (!ofs)
    {
        std::cout << "ファイルが開けませんでした。" << std::endl;
        std::cin.get();
        return 0;
    }

    //現在のファイル位置を表示
    std::cout << "現在のファイル位置: " << ofs.tellp() << std::endl;

    //ofs << "abcde" << std::endl;
    std::string moji = "abcde";
    for(auto i = 0; i < moji.length(); i++){
        std::cout << "moji: " << moji[i] << std::endl;
        ofs << moji[i];
        std::cout << "現在のファイル位置: " << ofs.tellp() << std::endl;
    }

    //現在の位置から2文字分戻る
    ofs.seekp(-2, std::ios::cur);

    std::cout << "現在のファイル位置: " << ofs.tellp() << std::endl;
    ofs << "abcde" << std::endl;

    //std::cin.get();

    //↑で作ったファイルを読み取り専用で開く
    std::ifstream ifs(fileName);
    if (!ifs)
    {
        std::cout << "ファイルが開けませんでした。" << std::endl;
        std::cin.get();
        return 0;
    }

    std::string data;
    //ファイルからstringにデータ格納
    std::string buf;
    while (!ifs.eof())
    {
        std::getline(ifs, buf);
        data += buf + "\n";
    }
    std::cout << "ファイルの中身：" << data << std::endl;

    std::cin.get();
}