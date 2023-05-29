class ParkingSystem {
public:
    int big;
    int small;
    int medium;
    ParkingSystem(int big, int medium, int small) {
        this->big=big;
        this->medium=medium;
        this->small=small;
    }
    
    bool addCar(int carType) {
        if(carType == 1)
        {
            big--;
            return big>=0;
        }
        else if(carType == 2)
        {
            medium--;
            return medium>=0;
        }
        else if(carType == 3)
        {
             small--;
            return small>=0;
        }
        return false;
}
};