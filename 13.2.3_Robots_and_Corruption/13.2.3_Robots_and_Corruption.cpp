/*Задание 3. Роботы и коррупция*
Улучшите электронную очередь для роботов. К нам приходят роботы разного социального статуса.
Каждый робот вводит не только свой уникальный номер, но и свое место в очереди. Например, 
пусть в нашей очереди 10 роботов и к нам приходит 11-й. Сначала он вводит свой номер, как
и раньше, а затем свое место в очереди - например, 5. В этом случае он должен оказаться в
очереди пятым, а все остальные, начиная со старого пятого - подвинуться дальше в конец очереди.
Реализуйте функцию std::vector<int> add_to_position(std::vector vec, int val, int position)*/

#include <iostream>
#include <vector>

std::vector<int> add_to_position(std::vector<int>& vec, int val, int position) {
    if (position >= vec.size()) {
        // Если позиция больше или равна размеру вектора, просто добавляем элемент в конец
        vec.push_back(val);
    }
    else {
        // Вставляем элемент на указанную позицию и сдвигаем остальные элементы вправо
        vec.insert(vec.begin() + position, val);
    }

    return vec;
}

int main() {
    std::cout << "How many Androids?" << '\n';

    std::vector<int> vec{ 1, 2, 3, 4 };

    int number = 0;
    while (number != -1)
    {
        std::cout << "Please enter your number: ";
        std::cin >> number;
        if (number != -1)
        {
            int position = 0;
            std::cout << "Please enter your position: ";
            std::cin >> position;
            vec = add_to_position(vec, number, position);
        }
    }

    std::cout << "Androids in queue:\n";
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << '\n';

    return 0;
}
