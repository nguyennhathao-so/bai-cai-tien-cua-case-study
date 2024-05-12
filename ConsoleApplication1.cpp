#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm> // Dùng để sắp xếp vector
#include "salary.h"

using namespace std;

int main() {
    srand(time(NULL));
    cout << fixed << setprecision(2);

    // Khởi tạo vector chứa 10 đối tượng Employee
    vector<Employee*> employees;

    // Tạo 10 đối tượng cho mỗi loại Employee với thông tin ngẫu nhiên
    for (int i = 0; i < 10; ++i) {
        SalariedEmployee* salariedEmployee = new SalariedEmployee("","","",0.0);
        salariedEmployee->sinhSEmployee();
        employees.push_back(salariedEmployee);

        CommissionEmployee* commissionEmployee = new CommissionEmployee();
        commissionEmployee->sinhCEmployee();
        employees.push_back(commissionEmployee);
        
        BasePlusCommissionEmployee* basePlusCommissionEmployee = new BasePlusCommissionEmployee();
        basePlusCommissionEmployee->sinhBPCEmployee();
        employees.push_back(basePlusCommissionEmployee); // Lưu ý: Đã thêm dấu & để truyền địa chỉ của đối tượng
        
    }

    // Sắp xếp danh sách theo thứ tự giảm dần của thu nhập
    sort(employees.begin(), employees.end(),
        [](const Employee* a, const Employee* b) {// dùng hàm lambda
            return a->earnings() > b->earnings();//nếu đúng thì trả về true
        });

    // In danh sách ra màn hình
    cout << "Danh sach nhan vien theo thu tu giam dan caa thu nhap:\n\n";
    for (size_t i = 0; i < employees.size(); ++i) {
        employees[i]->print();
        cout << "\nearned $" << employees[i]->earnings() << "\n\n";
    }

    // Giải phóng bộ nhớ
    for (size_t i = 0; i < employees.size(); ++i) {
        delete employees[i];
    }

    return 0;
}
