#include<iostream>
#include<string>
#include <bitset>
using namespace std;

string CalculateNetmask(const char *rhs,const char* lhs)
{
    string rhs_str(rhs),lhs_str(lhs);
    size_t dot_pos1 = rhs_str.find(".");
    size_t dot_pos2 = lhs_str.find(".");
    bitset<8> rhs_bits(stoi(string(rhs_str.begin(),rhs_str.begin() + dot_pos1)));
    bitset<8> lhs_bits(stoi(string(lhs_str.begin(),lhs_str.begin() + dot_pos2)));
    rhs_bits.operator&=(lhs_bits);
    if(!rhs_bits.test(0))
    {
        return string("not within a subnetwork");
    }
    string netmask(to_string(rhs_bits.to_ulong()) + ".");

    size_t old_pos1 = dot_pos1 ,old_pos2 = dot_pos2 ;
    dot_pos1 = rhs_str.find(".",old_pos1 + 1);
    dot_pos2 = lhs_str.find("." ,old_pos2 + 1);
    rhs_bits = stoi(string(rhs_str.begin() + old_pos1 + 1 ,rhs_str.begin() + dot_pos1));
    lhs_bits = stoi(string(lhs_str.begin() + old_pos2 + 1 ,lhs_str.begin() + dot_pos2));
    rhs_bits.operator&=(lhs_bits);
    netmask += to_string(rhs_bits.to_ulong()) + ".";

    old_pos1 = dot_pos1;
    old_pos2 = dot_pos2;
    dot_pos1 = rhs_str.find(".",old_pos1 + 1);
    dot_pos2 = lhs_str.find("." ,old_pos2 + 1);
    rhs_bits = stoi(string(rhs_str.begin() + old_pos1 + 1 ,rhs_str.begin() + dot_pos1));
    lhs_bits = stoi(string(lhs_str.begin() + old_pos2 + 1 ,lhs_str.begin() + dot_pos2));
    rhs_bits.operator&=(lhs_bits);
    netmask += to_string(rhs_bits.to_ulong()) + ".";

    rhs_bits = stoi(string(rhs_str.begin() + dot_pos1 + 1 ,rhs_str.end()));
    lhs_bits = stoi(string(lhs_str.begin() + dot_pos2 + 1 ,lhs_str.end()));
    rhs_bits.operator&=(lhs_bits);
    netmask += to_string(rhs_bits.to_ulong()) ;
    return netmask;

}

int main()
{
    char ip1[16],ip2[16];
    cin >> ip1 >> ip2;
    cout << CalculateNetmask(ip1,ip2);

}