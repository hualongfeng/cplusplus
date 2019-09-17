#include <iostream>
#include <string>

struct Sales_data{
  std::string isbn() const {return bookNo;}
  Sales_data& combine(const Sales_data&);
  double avg_price() const;

  std::string bookNo;
  unsigned int units_sold = 0;
  double revenue = 0.0;
}

Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&)


double Sales_data::avg_price() const
{
  if(units_sold)
    return revenue/units_sold;
  else
    return 0;
}

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}

std::ostream &print(std::ostream& os, const Sales_data& item)
{
  os << item.isbn() << 
}


int main()
{
  Sales_data total;

  return 0;
}
