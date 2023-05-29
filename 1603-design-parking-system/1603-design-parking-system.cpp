class ParkingSystem {
public:
    int big=0,med=0,small=0;
    ParkingSystem(int big, int medium, int small) {
        this->big=big;
        this->med=medium;
        this->small=small;
    }
    
    bool addCar(int carType) {
        if(carType==1 and big>0){
            big--;
            return true;
        }
        if(carType==2 and med>0){
            med--;
            return true;
        }
        if(carType==3 and small>0){
            small--;
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */