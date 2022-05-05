#include <iostream>
#include <string.h>

class Vehicle
{
private:
    char *color{nullptr}, *brand{nullptr}, *model{nullptr};

public:
    Vehicle()
    {
        this->color = nullptr;
        this->brand = nullptr;
        this->model = nullptr;
    }

    Vehicle(char *color, char *brand, char *model) : Vehicle()
    {
        this->color = new char[strlen(color) + 1];
        strcpy(this->color, color);
        this->brand = new char[strlen(brand) + 1];
        strcpy(this->brand, brand);
        this->model = new char[strlen(model) + 1];
        strcpy(this->model, model);
    }

    Vehicle(const Vehicle &v)
    {
        this->color = new char[strlen(v.color) + 1];
        strcpy(this->color, v.color);
        this->brand = new char[strlen(v.brand) + 1];
        strcpy(this->brand, v.brand);
        this->model = new char[strlen(v.model) + 1];
        strcpy(this->model, v.model);
    }

    Vehicle &operator=(const Vehicle &v)
    {
        if (this != &v)
        {
            delete[] this->color;
            this->color = new char[strlen(v.color) + 1];
            delete[] this->brand;
            this->brand = new char[strlen(v.brand) + 1];
            delete[] this->model;
            this->model = new char[strlen(v.model) + 1];
            strcpy(this->color, v.color);
            strcpy(this->brand, v.brand);
            strcpy(this->model, v.model);
        }
        return *this;
    }

    ~Vehicle()
    {
        delete[] this->color;
        delete[] this->brand;
        delete[] this->model;
    }

    char *getColor() { return this->color; }
    char *getBrand() { return this->brand; }
    char *getModel() { return this->model; }
};

class Parking_Lot
{
private:
    char *address{nullptr}, *lot_Id{nullptr};
    int price{0}, earning{0}, num{0};
    Vehicle *arr{nullptr};

public:
    Parking_Lot()
    {
        this->address = nullptr;
        this->lot_Id = nullptr;
        this->arr = nullptr;
        this->num = 0;
    }

    Parking_Lot(char *address, char *lot_Id, int price) : Parking_Lot()
    {
        this->address = new char[strlen(address) + 1];
        strcpy(this->address, address);
        this->lot_Id = new char[strlen(lot_Id) + 1];
        strcpy(this->lot_Id, lot_Id);
        this->price = price;
    }

    Parking_Lot(const Parking_Lot &p_l)
    {
        this->address = new char[strlen(p_l.address) + 1];
        strcpy(this->address, p_l.address);
        this->lot_Id = new char[strlen(p_l.lot_Id) + 1];
        strcpy(this->lot_Id, p_l.lot_Id);
        this->price = p_l.price;
        this->earning = p_l.earning;
        this->num = p_l.num;
        delete[] this->arr;
        this->arr = new Vehicle[this->num];
        for (int i = 0; i < this->num; i++)
        {
            this->arr[i] = p_l.arr[i];
        }
    }

    Parking_Lot &operator=(const Parking_Lot &p_l)
    {
        if (this != &p_l)
        {
            delete[] this->address;
            this->address = new char[strlen(p_l.address) + 1];
            strcpy(this->address, p_l.address);
            delete[] this->lot_Id;
            this->lot_Id = new char[strlen(p_l.lot_Id) + 1];
            strcpy(this->lot_Id, p_l.lot_Id);
            this->price = p_l.price;
            this->earning = p_l.earning;
            this->num = p_l.num;
            delete[] this->arr;
            this->arr = new Vehicle[this->num];
            for (int i = 0; i < this->num; i++)
            {
                this->arr[i] = p_l.arr[i];
            }
        }
        return *this;
    }

    Vehicle &operator+=(const Vehicle &v)
    {
        Vehicle *tmp = new Vehicle[this->num + 1];
        for (int i = 0; i < this->num; i++)
        {
            tmp[i] = this->arr[i];
        }
        tmp[this->num++] = v;
        delete[] this->arr;
        this->arr = tmp;
    }

    ~Parking_Lot()
    {
        delete[] this->address;
        delete[] this->lot_Id;
        delete[] this->arr;
    }

    char *getId() { return this->lot_Id; }
    void pay(int hours) { this->earning += this->price * hours; }
    bool isEqual_address(Parking_Lot &p_l) { return (strcmp(this->address, p_l.address) == 0); }

    void print()
    {
        std::cout << this->lot_Id << " " << this->address;
        if (earning)
        {
            std::cout << " - " << this->earning << " denari";
        }
        std::cout << std::endl;
    }
    void print_all()
    {
        std::cout << "Vo parkingot se parkirani slednite vozila:" << std::endl;
        for (int i = 0; i < this->num; i++)
        {
            std::cout << i + 1 << "." << this->arr[i].getColor() << " " << this->arr[i].getBrand() << " " << this->arr[i].getModel() << std::endl;
        }
    }
};

int main()
{
    Parking_Lot p[100];
    int n, m, hours, price_per_hour;
    char address[50], id[50];
    std::cin >> n;

    if (n > 0)
    {
        for (int i = 0; i < n; i++)
        {
            std::cin.get();
            std::cin.getline(address, 50);
            std::cin >> id >> price_per_hour;
            Parking_Lot p_l(address, id, price_per_hour);
            p[i] = p_l;
        }

        std::cin >> m;
        for (int i = 0; i < m; i++)
        {
            std::cin >> id >> hours;
            int findId = false;
            for (int j = 0; j < n; j++)
            {
                if (strcmp(p[j].getId(), id) == 0)
                {
                    p[j].pay(hours);
                    findId = true;
                }
            }
            if (!findId)
            {
                std::cout << "Ne e platen parking. Greshen ID." << std::endl;
            }
        }

        std::cout << "=========" << std::endl;
        Parking_Lot pl_1("Cvetan Dimov", "C10", 80);
        for (int i = 0; i < n; i++)
        {
            if (p[i].isEqual_address(pl_1))
            {
                p[i].print();
            }
        }
    }

    else
    {
        Parking_Lot pl_2("Mars", "1337", 1);
        int occupancy;
        std::cin >> occupancy;

        for (int i = 0; i < occupancy; i++)
        {
            char color[20], brand[20], model[20];
            std::cin >> color >> brand >> model;
            Vehicle new_vehicle(color, brand, model);
            pl_2 += new_vehicle;
        }

        if (occupancy != 0)
        {
            pl_2.print_all();
        }
    }

    return 0;
}