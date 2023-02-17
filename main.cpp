#include <iostream>
#include <fstream>
#include <memory>

//C:\Users\К - 14\Documents\Суслов Игорь\OOP21\x64\Debug


    //SOLID - один из принципов составления программ в ООП: 
    // S - Единственная ответственность (один объект, класс отвечает сам за себя).
    // O - Принцип Открытости/Закрытости (классы (программыне сущности) должны быть открыты для расширения но закрыты для модификации)
    // L - Принцип подстановки Лисков (функции которые используют базовый тип должны иметь возможность использовать подтипы базового типа не зная об этом, функции использующие базовый класс должны иметь возможность использовать наследников не зная об этом)
    // I - Принцип разделения интерфейсов ((больше интерфейсов малых) -много интерфейсов специально предназначенных для клиетов лучше, чем один (большой) общего назначения)
    // D - Принцип инверсии зависимостей (зависимость от абстракций а не от реализации)
 
//Патерн проектирования: фабричный метод
//Будет Базовый класс с фабричным методом Диалог, фабричный метод создать кнопку (для разных ОС и веба)
//Будут наследники с реализацией фабричного метода (создать кнопку)

class Button {
public:
    virtual void render() = 0;
    virtual ~Button() {};
};

class WindowsButton : public Button {
public:
    void render() override {
        std::cout << "Render Windows Button\n";
    }
};

class HTMLButton : public Button {
public:
    void render() override {
        std::cout << "Render HTML Button\n";
    }
};

class Dialog {
public:
    //Dialog();
    virtual ~Dialog(){};
    void render() {
        std::shared_ptr<Button> button = createButton();
        button->render();
    }
    virtual std::shared_ptr<Button> createButton() = 0;
private:
};

class WindowsDialog : public Dialog {
public:
    std::shared_ptr<Button> createButton() override {
        return std::make_shared <WindowsButton>();
    }
};

class WebDialog : public Dialog {
public:
    std::shared_ptr<Button> createButton() override {
        return std::make_shared <HTMLButton>();
    }
};



int main(int argc, char** argv) {

    //Аргументы командной строки
   /* if (argc > 1) {
        for (int i = 0; i < argc; i++) {
            std::string s = std::string (argv[i]);
            std::cout << s << std::endl;
        }

        std::string filename = std::string(argv[1]);
        std::cout << filename << std::endl; //в проекте выводить не надо
        std::ifstream fin(filename); // тоже самое std::ifstream fin("filename.ini");
    }
    else {
        std::cout << "Only one argument was provided" << std::endl;
    }


   // std::cout << "Hello World!\n";*/


   //Патерн проектирования: фабричный метод
  /*  std::shared_ptr<Dialog> dialog;

    std::string config;
    std::cout << "Enter config (Windows or Web): \n";
    std::cin >> config;

    if (config == "Windows") {
        dialog = std::make_shared<WindowsDialog>();
    }
    else if (config == "Web") {
        dialog = std::make_shared<WebDialog>();
    }
    else {
        throw "Error: unknown confing\n";
    }

    dialog->render();*/

 
    return 0;
};