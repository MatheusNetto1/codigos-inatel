#include <iostream>
#include <algorithm>

struct Box {
    int height, width, length;
};

int main() {
    // Dimens�es do container
    int containerHeight, containerWidth, containerLength;
    std::cin >> containerHeight >> containerWidth >> containerLength;

    // Tipos de caixas
    Box boxes[3] = {
        {1, 1, 3},  // Caixa B volume 3
        {2, 2, 1},  // Caixa C volume 4
        {5, 2, 2}   // Caixa A volume 20
    };

    // Conta quantas caixas de cada tipo podem ser colocadas no container
    int count[3] = {0, 0, 0};
    for (int i = 0; i < 3; ++i) {
        while (containerHeight >= boxes[i].height && containerWidth >= boxes[i].width && containerLength >= boxes[i].length) {
            ++count[i];
            containerHeight -= boxes[i].height;
            containerWidth -= boxes[i].width;
            containerLength -= boxes[i].length;
        }
    }

    std::cout << "Caixas A: " << count[2] << "\n";
    std::cout << "Caixas B: " << count[0] << "\n";
    std::cout << "Caixas C: " << count[1] << "\n";

    return 0;
}
