#pragma once
#include <string>
#include<iostream>
using namespace std;

// lớp trừu tượng Employee
class Employee
{
private:
    string firstName;
    string lastName;
    string socialSecurityNumber;

public:
    Employee() : firstName(""), lastName(""), socialSecurityNumber("") {}
    Employee(const string&, const string&, const string&);//constructor 
    void setFirstName(const string&);//cập nhập FirstName;
    string getFirstName() const;//xuất thông tin FirstName
    void taoao();
    void setLastName(const string&);
    string getLastName() const;

    void setSocialSecurityNumber(const string&);
    string getSocialSecurityNumber() const;

    virtual double earnings() const = 0;//hàm thuần ảo 
    virtual void print() const;
};


//tạo lớp SalariedEmployee kế thừa từ lớp Employee "public"
class SalariedEmployee : public Employee
{
private:
    double weeklySalary;

public:
    SalariedEmployee() : Employee("", "", ""), weeklySalary(0.0) {}//constructor mặc định
    SalariedEmployee(const string&, const string&, const string&, double = 0.0);//constructor nếu nhập giá trị 
    void setWeeklySalary(double);
    double getWeeklySalary() const;

    virtual double earnings() const;
    virtual void print() const;
    void sinhSEmployee();//sinh ra ngẫu nhiên thông tin của SalariedEmployee
};
//tạo lớp CommissionEmployee kế thừa từ lớp Employee "public"
class CommissionEmployee : public Employee
{
private:
    double grossSales;
    double commissionRate;

public:
    CommissionEmployee() : Employee("", "", ""), grossSales(0.0), commissionRate(0.0){}//constructor mặc định
    CommissionEmployee(const string&, const string&, const string&, double = 0.0, double = 0.0);//constructor nếu nhập giá trị 
    void sinhCEmployee();//sinh thông tin ngẫu nhiên của CommissionEmployee
    void setGrossSales(double);
    double getGrossSales() const;
    void setCommissionRate(double);
    double getCommissionRate() const;

    virtual double earnings() const;
    virtual void print() const;
};
//tạo lớp BasePlusCommissionEmployee kế thừa từ lớp CommissionEmployee "public"
class BasePlusCommissionEmployee : public CommissionEmployee
{
private:
    double baseSalary;

public:
    BasePlusCommissionEmployee() : CommissionEmployee("","","",0.0,0.0) ,baseSalary(0.0){}
    BasePlusCommissionEmployee(const string&, const string&, const string&, double = 0.0, double = 0.0, double = 0.0);
    void setBaseSalary(double);
    double getBaseSalary() const;
    void sinhBPCEmployee();////sinh thông tin ngẫu nhiên của BasePlusCommissionEmployee
    virtual double earnings() const;
    virtual void print() const;
};
