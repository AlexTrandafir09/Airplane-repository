#include <iostream>
#include <cstring>
using namespace std;
class engine {
    char *model;
    char *combustion;
    int horse_power;
public:
    engine() {
        model = new char[0];
        combustion = new char[0];
        horse_power = 0;
    }

    engine(const char *model_, const char *combustion_, const int horse_power_) {
        model = new char[strlen(model_) + 1];
        combustion = new char[strlen(combustion_) + 1];
        horse_power = horse_power_;
        strcpy(model, model_);
        strcpy(combustion, combustion_);
    }

    engine(const engine &engine_copy) {
        model = new char[strlen(engine_copy.model) + 1];
        combustion = new char[strlen(engine_copy.combustion) + 1];
        horse_power = engine_copy.horse_power;
        strcpy(model, engine_copy.model);
        strcpy(combustion, engine_copy.combustion);
    }

    [[nodiscard]] const char* getEngineModel()const{
        return model;
    }

    [[nodiscard]] char* getEngineCombustion()const{
        return combustion;
    }

    [[nodiscard]] int getHorsePower()const{
        return horse_power;
    }

    void setEngineModel(const char* model_) {
        delete[] model;
        model = new char[strlen(model_) + 1];
        strcpy(model, model_);
    }

    void setEngineCombustion(const char *combustion_) {
        delete[] combustion;
        combustion = new char[strlen(combustion_) + 1];
        strcpy(combustion, combustion_);
    }

    void setHorsePower(const int horse_power_) {
        horse_power = horse_power_;
    }

    bool operator==(const engine &rhs) const {
        return strcmp(model, rhs.model) == 0 and strcmp(combustion, rhs.combustion) == 0 and
               horse_power == rhs.horse_power;
    }

    bool operator!=(const engine &rhs) const {
        return strcmp(model, rhs.model) != 0 and strcmp(combustion, rhs.combustion) != 0 and
               horse_power != rhs.horse_power;
    }

    engine &operator=(const engine &rhs) {
        setEngineModel(rhs.model);
        setEngineCombustion(rhs.combustion);
        setHorsePower(rhs.horse_power);
        return *this;}



    ~engine(){
        delete[] model;
        delete[] combustion;}

    friend class avion;

};
class plane{
    char* plane_name;
    char* manufacturer;
    float plane_length;
    long max_distance;
    unsigned year_of_fabrication;
public:
    plane(){
        plane_name=new char[0];
        manufacturer=new char[0];
        plane_length=0.0;
        max_distance=0;
        year_of_fabrication=0;
    }

    plane(const char *plane_name_, const char *manufacturer_, const float plane_length_,
          const long max_distance_, const unsigned year_of_fabrication_){
        plane_name=new char[strlen(plane_name_) + 1];
        manufacturer=new char[strlen(manufacturer_) + 1];
        plane_length=plane_length_;
        max_distance=max_distance_;
        year_of_fabrication=year_of_fabrication_;
        strcpy(plane_name, plane_name_);
        strcpy(manufacturer, manufacturer_);
    }
    plane(const plane& plane_copy){
        plane_name=new char[strlen(plane_copy.plane_name) + 1];
        manufacturer=new char[strlen(plane_copy.manufacturer) + 1];
        plane_length=plane_copy.plane_length;
        max_distance=plane_copy.max_distance;
        year_of_fabrication=plane_copy.year_of_fabrication;
        strcpy(manufacturer, plane_copy.manufacturer);
        strcpy(plane_name, plane_copy.plane_name);
    }
    [[nodiscard]] char* getPlaneName()const{
        return plane_name;
    }
    [[nodiscard]] char* getManufacturer()const{
        return manufacturer;
    }
    [[nodiscard]] float getPlaneLength()const{
        return plane_length;
    }
    [[nodiscard]] long getMaxDistance()const{
        return max_distance;
    }
    [[nodiscard]] unsigned getYearOfFabrication()const{
        return year_of_fabrication;}

    void setPlaneName(const char* plane_name_){
        delete[] plane_name;
        plane_name=new char[strlen(plane_name_) + 1];
        strcpy(plane_name, plane_name_);
    }
    void setManufacturer(const char* manufacturer_){
        delete[] manufacturer;
        manufacturer=new char[strlen(manufacturer_) + 1];
        strcpy(manufacturer, manufacturer_);
    }
    void setYearOfFabrication(const unsigned year_of_fabrication_){
        year_of_fabrication=year_of_fabrication_;
    }
    void setPlaneLength(const float plane_length_){
        plane_length=plane_length_;
    }
    void setMaxDistance(const long max_distance_){
        max_distance=max_distance_;
    }
    bool operator==(const plane &rhs)const{
        return strcmp(plane_name, rhs.plane_name) == 0 and strcmp(manufacturer, rhs.manufacturer) == 0
               and plane_length == rhs.plane_length and max_distance == rhs.max_distance and year_of_fabrication ==
                                                                                             rhs.year_of_fabrication;
    }
    bool operator!=(const plane &rhs)const{
        return strcmp(plane_name, rhs.plane_name) != 0 and strcmp(manufacturer, rhs.manufacturer) != 0
               and plane_length != rhs.plane_length and max_distance != rhs.max_distance and
               year_of_fabrication != rhs.year_of_fabrication;
    }
    plane& operator=(const plane& rhs)
    {
        setPlaneName(rhs.plane_name);
        setYearOfFabrication(rhs.year_of_fabrication);
        setManufacturer(rhs.manufacturer);
        setMaxDistance(rhs.max_distance);
        setPlaneLength(rhs.plane_length);

        return *this;
    }
    ~plane(){
        delete[] plane_name;
        delete[] manufacturer;

    }
    friend class engine;

};

istream& operator>>(istream& is, engine& engine1){
    is.get();
    char model[50],combustion[50];
    int horse_power;
    cout<<"Type the model of the engine: ";
    is.getline(model,48);
    engine1.setEngineModel(model);
    cout<<"Type the combustion of the engine: ";is.getline(combustion,48);
    engine1.setEngineCombustion(combustion);
    cout<<"Type the horse power of the engine: ";
    is>>horse_power;
    engine1.setHorsePower(horse_power);
    return is;
}
ostream& operator<<(ostream& os, engine& engine1){
    os << "Engine model: " << engine1.getEngineModel() << endl;
    os << "Combustion: " << engine1.getEngineCombustion() << endl;
    os << "Horse power: " << engine1.getHorsePower() << endl;
    return os;
}

istream& operator>>(istream& is, plane& plane1){
    is.get();
    char plane_name[50],manufacturer[50];
    int plane_length,max_distance,yearOfFabrication;
    cout<<"Type the name of the plane: ";is.getline(plane_name, 48);
    plane1.setPlaneName(plane_name);
    cout<<"Type the manufacturer of the airplane: ";is.getline(manufacturer, 48);
    plane1.setManufacturer(manufacturer);
    cout<<"Type the length of the airplane(m): ";
    is >> plane_length;
    plane1.setPlaneLength(plane_length);
    cout<<"Type the maximum distance of the airplane(km): ";
    is >> max_distance;
    plane1.setMaxDistance(max_distance);
    cout<<"Type the year of fabrication of the airplane: ";
    is >> yearOfFabrication;
    plane1.setYearOfFabrication(yearOfFabrication);
    return is;
}
ostream& operator<<(ostream& os, plane& plane1){
    os << "Name of the plane: " << plane1.getPlaneName() << endl;
    os << "Manufacturer of the airplane: " << plane1.getManufacturer() << endl;
    os << "Length of the airplane(m): " << plane1.getPlaneLength() << endl;
    os << "Maximum distance of the airplane(km): " << plane1.getMaxDistance() << endl;
    os << "Year of fabrication of the airplane: " << plane1.getYearOfFabrication() << endl;
    return os;

}
int main(){
    int nr_airplanes=3,nr_engines=3;
    auto* v_plane=new plane[3];
    auto* v_engine=new engine[3];

    v_plane[0].setPlaneName("BOEING 737-800");
    v_plane[0].setPlaneLength(40);
    v_plane[0].setMaxDistance(5600);
    v_plane[0].setYearOfFabrication(1996);
    v_plane[0].setManufacturer("BOEING 737 CLASSICS");
    v_engine[0].setEngineModel("CFM International CFM56");
    v_engine[0].setEngineCombustion("Kerosen");
    v_engine[0].setHorsePower(50000);

    v_plane[1].setPlaneName("AIRBUS A321");
    v_plane[1].setPlaneLength(44.51);
    v_plane[1].setMaxDistance(7400);
    v_plane[1].setYearOfFabrication(1994);
    v_plane[1].setManufacturer("AIRBUS GROUP");
    v_engine[1].setEngineModel("International Aero Engines V2530-A5");
    v_engine[1].setEngineCombustion("Kerosen");
    v_engine[1].setHorsePower(56000);

    v_plane[2].setPlaneName("BOEING 777");
    v_plane[2].setPlaneLength(63.7);
    v_plane[2].setMaxDistance(9420);
    v_plane[2].setYearOfFabrication(1994);
    v_plane[2].setManufacturer("BOEING");
    v_engine[2].setEngineModel("GE90-115B");
    v_engine[2].setEngineCombustion("Kerosen");
    v_engine[2].setHorsePower(175000);

    bool open=true;
    short choice;
    do{
        cout<<"1)ADD plane"<<endl;
        cout<<"2)REMOVE plane"<<endl;
        cout<<"3)DISPLAY plane"<<endl;
        cout<<"4)SWITCH the characteristics of a plane"<<endl;
        cout<<"5)CLOSE"<<endl;
        cout<<"Choose:";cin >> choice;
        switch(choice) {
            case 1: {
                nr_airplanes++;
                auto *aux = new plane[nr_airplanes + 1];
                for (int index = 0; index < nr_airplanes - 1; index++)
                    aux[index] = v_plane[index];
                cin >> aux[nr_airplanes - 1];
                delete[] v_plane;
                v_plane = aux;
                nr_engines++;
                auto *aux1 = new engine[nr_engines];
                for (int index = 0; index < nr_engines - 1; index++)
                    aux1[index] = v_engine[index];
                cin >> aux1[nr_engines - 1];
                delete[] v_engine;
                v_engine = aux1;
                cout << "The plane was added successfully." << endl;
                break;
            }
            case 2: {
                char plane_name[50];
                bool ok = false;
                cout << "Name of the airplane you'd like to remove: ";
                cin.get();
                cin.getline(plane_name, 48);
                auto *aux = new plane[nr_airplanes - 1];
                auto *aux1 = new engine[nr_engines - 1];
                for (int index = 0; index < nr_airplanes; index++)
                    if (strcmp(v_plane[index].getPlaneName(), plane_name) == 0)
                        ok = true;


                if (!ok) {
                    cout << "There is no plane with the name you introduced." << endl;
                    break;
                }
                int i = 0;
                for (int index = 0; index < nr_airplanes; index++)
                    if (strcmp(v_plane[index].getPlaneName(), plane_name) != 0) {
                        aux[i] = v_plane[index];
                        aux1[i] = v_engine[index];
                        i++;
                    }
                delete[] v_plane;
                delete[] v_engine;
                v_plane = aux;
                v_engine = aux1;
                nr_airplanes--;
                nr_engines--;
                cout << "The plane with the name: " << plane_name << " has been removed off of the list." << endl;
                break;
            }
            case 3: {
                for (int index = 0; index < nr_airplanes; index++) {
                    cout << v_plane[index];
                    cout << v_engine[index];
                    cout << endl;
                }
                break;
            }
            case 4: {
                bool exists = false;
                char plane_name2[50];
                cout << "Type the name of the airplane you'd like to switch characteristics: ";
                cin.get();
                cin.getline(plane_name2, 48);
                for (int index = 0; index < nr_airplanes; index++)
                    if (strcmp(v_plane[index].getPlaneName(), plane_name2) == 0)
                        exists = true;

                if (!exists) {
                    cout << "There is no airplane with the name you introduced." << endl;
                    break;
                }
                for (int index = 0; index < nr_airplanes; index++)
                    if (strcmp(v_plane[index].getPlaneName(), plane_name2) == 0) {
                        bool open1 = true;
                        do {
                            cout << "1) Name of the plane" << endl;
                            cout << "2) Manufacturer" << endl;
                            cout << "3) Length of the plane" << endl;
                            cout << "4) Max distance" << endl;
                            cout << "5) Year of fabrication" << endl;
                            cout << "6) Engine model" << endl;
                            cout << "7) Engine combustion type " << endl;
                            cout << "8) Horse Power" << endl;
                            cout << "9) I don't want to edit anything." << endl;
                            short choice1;

                            cout << "Choose the characteristic you'd like to edit: ";
                            cin >> choice1;

                            switch (choice1) {
                                case 1: {
                                    char planeName1[50];
                                    cout << "New name of the plane: ";
                                    cin.get();
                                    cin.getline(planeName1, 48);
                                    v_plane[index].setPlaneName(planeName1);
                                    cout << "Success."<< endl;
                                    break;

                                }
                                case 2: {
                                    char manufacturer1[50];
                                    cout << "New value for manufacturer: ";
                                    cin.get();
                                    cin.getline(manufacturer1, 48);
                                    v_plane[index].setManufacturer(manufacturer1);
                                    cout << "Success." << endl;
                                    break;
                                }
                                case 3: {
                                    float plane_length_1;
                                    cout << "New value for plane length: ";
                                    cin >> plane_length_1;
                                    v_plane[index].setPlaneLength(plane_length_1);
                                    cout << "Success." << endl;
                                    break;
                                }
                                case 4: {
                                    long max_distance1;
                                    cout << "New value for max distance: ";
                                    cin >> max_distance1;
                                    v_plane[index].setMaxDistance(max_distance1);
                                    cout << "Success." << endl;
                                    break;
                                }
                                case 5: {
                                    unsigned year;
                                    cout << "New value for the year of fabrication: ";
                                    cin >> year;
                                    v_plane[index].setYearOfFabrication(year);
                                    cout << "Success."<< endl;
                                    break;
                                }
                                case 6: {
                                    char model[50];
                                    cout << "New value for engine model: ";
                                    cin.get();
                                    cin.getline(model, 48);
                                    v_engine[index].setEngineModel(model);
                                    cout << "Success." << endl;
                                    break;

                                }
                                case 7: {
                                    char combustion1[50];
                                    cout << "New value for combustion: ";
                                    cin.get();
                                    cin.getline(combustion1, 48);
                                    v_engine[index].setEngineCombustion(combustion1);
                                    cout << "Success." << endl;
                                    break;
                                }
                                case 8: {
                                    int hp1;
                                    cout << "New value for horse power: ";
                                    cin >> hp1;
                                    v_engine[index].setHorsePower(hp1);
                                    cout << "Success." << endl;
                                    break;
                                }
                                case 9: {
                                    open1 = false;
                                    break;
                                }
                                default:
                                    cout << "The number you introduced is not associated with any of the functions." << endl;

                            }
                        } while (open1);
                    }
                break;
            }
            case 5: {
                open = false;
                break;
            }
            default:{
                cout << "The number you introduced is not associated with any of the functions" << endl;
                break;
            }
        }
    }while(open);
}
