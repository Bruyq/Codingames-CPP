#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <float.h>
#define M_PI           3.14159265358979323846

double degree_to_rad(double deg)
{
    return deg * M_PI / 180.0;
}

class Defibrillator
{
private:
    int m_id = 0;
    std::string m_name = "";
    std::string m_address = "";
    std::string m_phone_number = "";
    double m_longitude = 0;
    double m_latitude = 0;

public:
    Defibrillator() {};
    Defibrillator(std::string defibrillator_desc)
    {
        // m_id
        int idx = defibrillator_desc.find(';');
        std::string temp = defibrillator_desc.substr(0, idx);
        m_id = std::stoi(temp);
        defibrillator_desc = defibrillator_desc.substr(idx + 1);

        // m_name
        idx = defibrillator_desc.find(';');
        m_name = defibrillator_desc.substr(0, idx);
        defibrillator_desc = defibrillator_desc.substr(idx + 1);

        // m_address
        idx = defibrillator_desc.find(';');
        m_address = defibrillator_desc.substr(0, idx);
        defibrillator_desc = defibrillator_desc.substr(idx + 1);

        // m_phone_number
        idx = defibrillator_desc.find(';');
        m_phone_number = defibrillator_desc.substr(0, idx);
        defibrillator_desc = defibrillator_desc.substr(idx + 1);

        // m_longitude
        idx = defibrillator_desc.find(';');
        temp = defibrillator_desc.substr(0, idx);
        temp[temp.find(',')] = '.';
        m_longitude = degree_to_rad(std::stod(temp));

        // m_latitude
        temp = defibrillator_desc.substr(idx + 1);
        temp[temp.find(',')] = '.';
        m_latitude = degree_to_rad(std::stod(temp));
    }
    ~Defibrillator() {};
    std::string getName() { return m_name; }
    double distanceFromUser(double u_long, double u_lat)
    {
        double x = (m_longitude - u_long) * cos((m_longitude - u_long) / 2);
        double y = (m_latitude - u_lat);
        return std::sqrt(x * x + y * y) * 6371;
    }
};

int main()
{
    std::string lon;
    std::cin >> lon;  std::cin.ignore();
    lon[lon.find(',')] = '.';
    std::string lat;
    std::cin >> lat;  std::cin.ignore();
    lat[lat.find(',')] = '.';
    double u_long = degree_to_rad(std::stod(lon));
    double u_lat = degree_to_rad(std::stod(lat));
    double min_dist = DBL_MAX;
    double temp;
    std::string result;

    int n;
    std::cin >> n;  std::cin.ignore();
    for (int i = 0; i < n; i++) {
        std::string defib;
        std::getline(std::cin, defib);
        Defibrillator defibrillator(defib);
        temp = defibrillator.distanceFromUser(u_long, u_lat);
        if (temp <= min_dist)
        {
            min_dist = temp;
            result = defibrillator.getName();
        }
    }

    std::cout << result << std::endl;
}