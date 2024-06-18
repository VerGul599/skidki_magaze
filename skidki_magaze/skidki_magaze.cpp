#include <iostream> 
//#include <Windows.h> 
#include <cstdlib> 
#include <iomanip> 
#include <string> 
#include <limits> 

//магазин нижнего белья, trysishki 

int size = 10;
int receiptSize = 1;
double totalSum = 0;
int quantity = 0;
double price;
const int MAX_ITEMS = 10;

int* idArr = new int[size];
std::string* nameArr = new std::string[size];
int* countArr = new int[size];
double* priceArr = new double[size];

std::string* nameReceiptArr = new std::string[receiptSize];
int* countReceiptArr = new int[receiptSize];
double* priceReceiptArr = new double[receiptSize];

std::string names[MAX_ITEMS];
int quantities[MAX_ITEMS];
double prices[MAX_ITEMS];
int numItems = 0;

void Start();
void CreateStorage();
template <typename ArrType>
void FillArray(ArrType staticArray[], ArrType dinArray[], int size);
template <typename ArrType>
void PrintArray(ArrType arr[], int size);
void Shop();
void ShowStorage();
void Selling();
void AddElementToReceipt(int& receipSize, int Id, int count);
void PrintReceipt();
void ChangePrice();
void RemoveStorage();
void AddToStorage();
void ChangeStorage();
void AddElement();
void DeleteElement();
double calculateQuantityDiscount(int quantity, double price);
double calculateTotalSumDiscount(double totalSum);
void pauseConsole();
void CreateStorage2();


int main()
{
    /*SetConsoleCP(1251);
    SetConsoleOutputCP(1251);*/
    setlocale(LC_ALL, "ru");

    Start();
    CreateStorage();
    ShowStorage();
    Selling();

    delete[]idArr;
    delete[]nameArr;
    delete[]countArr;
    delete[]priceArr;
    delete[]nameReceiptArr;
    delete[]countReceiptArr;
    delete[]priceReceiptArr;

    system("pause");
    return 0;
}
void Start()
{
    std::string adminLogin = "ver599";
    std::string adminPassword = "nika";
    std::string login, password;
    bool exit = false;
    int choose;

    std::cout << "\n\t\t\tДобро пожаловать в Смерть Апрель\n\n";


    do
    {
        std::cout << "Логин: ";
        std::getline(std::cin, login, '\n');
        std::cout << "Пароль: ";
        std::getline(std::cin, password, '\n');

        if (login != adminLogin || password != adminPassword)
        {
            std::cerr << "Неверный логин и пароль\n\n";
            std::cout << "Попробовать ещё раз? \n1 - Да \n2 - Выход из программы\n";
            std::cin >> choose;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (choose == 2)
            {
                exit = true;
            }
        }
        else
        {
            exit = true;
            int chooseStorageType;
            do
            {
                std::cout << "Выберите формат склада: \n1 - Готовый склад\n2 - Создать склад вручную\n";
                std::cin >> chooseStorageType;
            } while (chooseStorageType < 1 || chooseStorageType > 2);
            if (chooseStorageType == 1)
            {
                CreateStorage();
                Shop();

            }
            else if (chooseStorageType == 2)
            {
                CreateStorage2();
                Shop();
            }
            else
            {
                std::cerr << "Error chooseStorageType";
            }
        }
    } while (!exit);
}
void CreateStorage()
{
    const int staticSize = 10;
    int id[staticSize]{ 0,1,2,3,4,5,6,7,8,9 };
    std::string name[staticSize]{ "Сорочка\t","Комплект жен. трусиков\t","Комплект муж. боксеров\t" ,
     "Лифчик\t" ,"Топ с вырезом\t" ,"Топ беж.\t",
     "Майка муж.\t","Майка жен.\t","Стринги жен.\t",
     "Парашуты муж.\t" };
    int count[staticSize]{ 8,4,5,8,10,2,3,6,8,5 };
    double price[staticSize]{ 599.0,699.0,799.0,490.99,520.99,499.0,600.50,599.99,299.0,400.0 };
    FillArray(id, idArr, staticSize);
    FillArray(name, nameArr, staticSize);
    FillArray(count, countArr, staticSize);
    FillArray(price, priceArr, staticSize);
}
void Shop()
{
    int choose;
    while (true)
    {
        do
        {
            std::cout << "1) Показать склад\n";
            std::cout << "2) Начать продажу\n";
            std::cout << "3) Изменить цену\n";
            std::cout << "4) Списасть товар\n";
            std::cout << "5) Пополнить товар\n";
            std::cout << "6) Изменение склада\n";
            std::cout << "0) Закончить смену\n";
            std::cin >> choose;
        } while (choose < 0 || choose > 6);

        if (choose == 1)
        {
            system("cls");
            ShowStorage();
        }
        else if (choose == 2) 
        {
            system("cls");
            Selling();
        }
        else if (choose == 3)
        {
            system("cls");
            ChangePrice();
        }
        else if (choose == 4) 
        {
            system("cls");
            RemoveStorage();
        }
        else if (choose == 5)
        {
            system("cls");
            AddToStorage();
        }
        else if (choose == 6)
        {
            system("cls");
            ChangeStorage();
        }
        else if (choose == 0)
        {
            break;
        }
        else
        {
            std::cerr << "Error";
        }
    }
}
void ShowStorage()
{
    int choose;
    std::cout << "Показать готовый склад или свой склад? \n1-Готовый склад\n2-Свой склад\n";
    std::cin >> choose;
    if (choose == 1) {
        std::cout << "\tid товара\tНазвание\t\t\tЦена\t\tКол-во\n\n";
        for (int i = 0; i < size; i++)
        {
            std::cout << "\t" << idArr[i] + 1 << "\t\t" << nameArr[i] << "\t\t\t" << priceArr[i] << "\t\t" << countArr[i] << "\n";
        }
    }
    else if (choose == 2) {

        std::cout << "\tНазвание\t\t\tЦена\t\tКол-во\n\n";

        for (int i = 0; i < numItems; i++) {
            std::cout << "\t" << names[i] << "\t\t\t" << quantities[i] << "\t\t" << prices[i] << "\n";
        }

    }
    else
    {

        std::cout << "Error";

    }

}
void Selling()
{

    int chooseId, chooseCount, confirm;
    bool isFirst = true;
    while (true)
    {
        do
        {
            std::cout << "Введите id товара для покупки: ";
            std::cin >> chooseId;
            if (chooseId < 1 || chooseId > size)
            {
                std::cerr << "Нет такого Id\n";
                continue;
            }
            if (countArr[chooseId - 1] > 0)
            {
                while (true)
                {
                    std::cout << "\nВы выбрали: " << nameArr[chooseId - 1] << "\n";
                    std::cout << "Кол-во товара на складе: " << countArr[chooseId - 1] << "\n";
                    std::cout << "Выберите кол-во товара для покупки: ";
                    std::cin >> chooseCount;
                    if (chooseCount < 1 || chooseCount > countArr[chooseId - 1])
                    {
                        std::cerr << "Товара не хватает\n";
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else
            {
                std::cerr << "Этот товар отстутствет на скалде";
                continue;
            }

            std::cout << "\nВы выбрали: " << nameArr[chooseId - 1] << "\n";
            std::cout << "В кол-ве " << chooseCount << "\n";
            std::cout << "Подтвердите выбор: \n1 - подтвердить\n2 - повторить\n";
            std::cin >> confirm;

            if (confirm == 1)
            {
                if (isFirst)
                {
                    isFirst = false;
                    nameReceiptArr[receiptSize - 1] = nameArr[chooseId - 1];
                    countReceiptArr[receiptSize - 1] = chooseCount;
                    priceReceiptArr[receiptSize - 1] = priceArr[chooseId - 1] * chooseCount;
                    countArr[chooseId - 1] -= chooseCount;
                }
                else if (!isFirst)
                {
                    AddElementToReceipt(receiptSize, chooseId, chooseCount);
                }
            }
            else
            {
                continue;
            }
            std::cout << "Купить еще 1 товар ?";
            std::cout << "\n1 - Да 2 - Неть;)\n Ваш выбор: ";
            std::cin >> confirm;
            if (confirm == 2)
            {
                break;
            }

        } while (true);
        system("cls");
        PrintReceipt();
        break;

    }

}
template<typename ArrType>
void PrintArray(ArrType arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}
void AddElementToReceipt(int& receipSize, int Id, int count)
{
    std::string* nameReceiptTemp = new std::string[receiptSize];
    int* countReceiptArrTemp = new int[receiptSize];
    double* priceReceiptArrTemp = new double[receiptSize];

    for (int i = 0; i < receiptSize; i++)
    {
        nameReceiptTemp[i] = nameReceiptArr[i];
        countReceiptArrTemp[i] = countReceiptArr[i];
        priceReceiptArrTemp[i] = priceReceiptArr[i];
    }
    delete[] nameReceiptArr;
    delete[] countReceiptArr;
    delete[] priceReceiptArr;

    receiptSize++;

    nameReceiptArr = new std::string[receiptSize];
    countReceiptArr = new int[receiptSize];
    priceReceiptArr = new double[receiptSize];

    for (int i = 0; i < receiptSize - 1; i++)
    {
        nameReceiptArr[i] = nameReceiptTemp[i];
        countReceiptArr[i] = countReceiptArrTemp[i];
        priceReceiptArr[i] = priceReceiptArrTemp[i];
    }

    nameReceiptArr[receiptSize - 1] = nameArr[Id - 1];
    countReceiptArr[receiptSize - 1] = count;
    priceReceiptArr[receiptSize - 1] = priceArr[Id - 1] * count;
    countArr[Id - 1] -= count;


    delete[] nameReceiptTemp;
    delete[] countReceiptArrTemp;
    delete[] priceReceiptArrTemp;
}
void PrintReceipt()
{
    std::cout << "Название\t\t\t\t\tЦена\t Кол - во\n\n";

    for (int i = 0; i < size; i++)
    {
        std::cout << "\t" << nameReceiptArr[i] << "\t" << countReceiptArr[i] << "\t\t\t" << priceReceiptArr[i] << "\t";
        totalSum += priceReceiptArr[i] * countReceiptArr[i];
    }

    double quantityDiscount = calculateQuantityDiscount(quantity, totalSum);
    double totalSumDiscount = calculateTotalSumDiscount(totalSum);

    std::cout << "Общая сумма: " << totalSum;
    if (quantityDiscount > 0)
    {
        std::cout << "Скидка за количество товаров: " << quantityDiscount;
    }
    if (totalSumDiscount > 0)
    {
        std::cout << "Скидка за общую сумму: " << totalSumDiscount;
    }
    double finalPrice = totalSum - quantityDiscount - totalSumDiscount;
    std::cout << "Итоговая цена: " << finalPrice;
}
void ChangePrice()
{
    int id;
    double newPrice = 0;
    do
    {
        std::cout << "Введите id товара:";
        std::cin >> id;
    } while (id <1 || id > idArr[size - 1]);
    std::cout << "\n\nТекущая цена:" << nameArr[id - 1] << "=" << priceArr[id - 1];
    do
    {
        std::cout << "Введите новую цену товара:";
        std::cin >> newPrice;
    } while (newPrice
        < 0.01 || newPrice > 100000.03);
    priceArr[id - 1] = newPrice;
    std::cout << "Изменение цены произошло успешно\n";

}
void RemoveStorage()
{

    int id;
    int goodCount;
    do
    {
        std::cout << "Введите id товара: ";
        std::cin >> id;

    } while (id<1 || id>idArr[size - 1]);
    std::cout << "\n\nТекущее количество товара: " << nameArr[id - 1] << " = " << countArr[id - 1];
    do
    {
        std::cout << "\nЧисло списывания товара: ";
        std::cin >> goodCount;

    } while (goodCount > countArr[id - 1]);
    countArr[id - 1] -= goodCount;
    std::cout << "\nCписание произошло успешно";





}
void AddToStorage()
{

    int id;
    int goodCount;
    do
    {
        std::cout << "Введите id товара: ";
        std::cin >> id;

    } while (id<1 || id>idArr[size - 1]);
    std::cout << "\n\nТекущее количество товара: " << nameArr[id - 1] << " = " << countArr[id - 1];
    do
    {
        std::cout << "\nЧисло добавления товара: ";
        std::cin >> goodCount;

    } while (goodCount < 0);
    countArr[id - 1] += goodCount;
    std::cout << "\nПополнение произошло успешно";

}
void ChangeStorage()
{
    int choose;
    do
    {
        std::cout << "Изменение склада. \nДобавить новый товар-1\nУдалить товар-2\nВыход-3\n";
        std::cin >> choose;
    } while (choose < 1 || choose>3);
    if (choose == 1)
    {
        AddElement();
    }
    else if (choose == 2)
    {
        DeleteElement();
    }
    else if (choose == 3)
    {
        std::cout << "Выход";
    }

}
void AddElement()
{

    int* idArrTemp = new int[size];
    std::string* nameArrTemp = new std::string[size];
    int* countArrTemp = new int[size];
    float* priceArrTemp = new float[size];


    for (int i = 0; i < size; i++)
    {
        idArrTemp[i] = idArr[i];
        nameArrTemp[i] = nameArr[i];
        countArrTemp[i] = countArr[i];
        priceArrTemp[i] = priceArr[i];
    }
    delete[] idArr;
    delete[] nameArr;
    delete[] countArr;
    delete[] priceArr;

    size++;

    idArr = new int[size];
    nameArr = new std::string[size];
    countArr = new int[size];
    priceArr = new double[size];


    for (int i = 0; i < size - 1; i++)
    {
        idArr[i] = idArrTemp[i];
        nameArr[i] = nameArrTemp[i];
        countArr[i] = countArrTemp[i];
        priceArr[i] = priceArrTemp[i];
    }

    idArr[size - 1] = size - 1;
    std::cout << "\nВведите имя нового товара: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, nameArr[size - 1], '\n');
    std::cout << "\nВведите кол-во нового товара: ";
    std::cin >> countArr[size - 1];
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\nВведите цену нового товара: ";
    std::cin >> priceArr[size - 1];
    std::cout << "\nТовар успешно добавлен\n\n";

    delete[] idArrTemp;
    delete[] nameArrTemp;
    delete[] countArrTemp;
    delete[] priceArrTemp;
}
void DeleteElement()
{

    int* idArrTemp = new int[size];
    std::string* nameArrTemp = new std::string[size];
    int* countArrTemp = new int[size];
    float* priceArrTemp = new float[size];


    for (int i = 0; i < size; i++)
    {
        idArrTemp[i] = idArr[i];
        nameArrTemp[i] = nameArr[i];
        countArrTemp[i] = countArr[i];
        priceArrTemp[i] = priceArr[i];
    }
    delete[] idArr;
    delete[] nameArr;
    delete[] countArr;
    delete[] priceArr;

    size--;

    idArr = new int[size];
    nameArr = new std::string[size];
    countArr = new int[size];
    priceArr = new double[size];

    int index = 0;
    std::cout << "Какой товар удалить? \nВведите id товара: ";
    std::cin >> index;
    for (int i = 0, j = 0; j < size, i < size; i++, j++)
    {
        if (i == index - 1)
        {
            i++;
            idArr[j] = idArrTemp[j];
            nameArr[j] = nameArrTemp[i];
            countArr[j] = countArrTemp[i];
            priceArr[j] = priceArrTemp[i];
        }
        else 
        {

            idArr[j] = idArrTemp[j];
            nameArr[j] = nameArrTemp[i];
            countArr[j] = countArrTemp[i];
            priceArr[j] = priceArrTemp[i];

        }
    }
    delete[] idArrTemp;
    delete[] nameArrTemp;
    delete[] countArrTemp;
    delete[] priceArrTemp;

}
template<typename ArrType>
void FillArray(ArrType staticArray[], ArrType dinArray[], int size)
{
    for (int i = 0; i < size; i++)
    {
        dinArray[i] = staticArray[i];
    }
}
double calculateQuantityDiscount(int quantity, double price) 
{
    if (quantity >= 5) 
    {
        return price * 0.1;
    }
    return 0;
}
double calculateTotalSumDiscount(double totalSum)
{
    if (totalSum >= 1000) 
    {
        return totalSum * 0.05;
    }
    return 0;
}
void pauseConsole() 
{
    std::cout << "Нажмите Enter для продолжения...";
    std::cin.get();
}
void CreateStorage2() 
{

    while (true)
    {
        system("cls");

        if (numItems >= MAX_ITEMS)
        {
            std::cout << "Склад полон! Невозможно добавить больше товаров.\n";
            break;
        }

        std::cout << "Введите название товара (или 'стоп' для завершения): ";
        std::cin >> names[numItems];
        std::cin.ignore();

        if (names[numItems] == "стоп")
        {
            break;
        }

        std::cout << "Введите количество: ";
        std::cin >> quantities[numItems];
        std::cin.ignore();

        std::cout << "Введите цену: ";
        std::cin >> prices[numItems];
        std::cin.ignore();

        numItems++;

        pauseConsole();
    }

    system("cls");

    std::cout << "Товары на складе:\n";
    for (int i = 0; i < numItems; i++)
    {
        std::cout << "\t" << names[i] << "\t\t\t" << quantities[i] << "\t\t" << prices[i] << "\n";
    }

    pauseConsole();
}
