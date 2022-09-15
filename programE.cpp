#include<iostream>

using namespace std;

#define MAX_ORDERS 50

struct ticket {
  char customer_name[100];
  int number_of_tickets;
};

int main() {
  int ticket_total = 50;
  int ticket_sold = 0;
  ticket tickets[MAX_ORDERS];
  while (ticket_total > 0) {
    ticket o;
    cout << "Enter the customer name: ";
    cin >> o.customer_name;
    cout << "Enter the number of tickets: ";
    cin >> o.number_of_tickets;
    if (o.number_of_tickets <= ticket_total) {
      tickets[ticket_sold] = o;
      ticket_total -= o.number_of_tickets;
      cout << "TICKET SOLD" << endl;
      ++ticket_sold;
    } else {
      cout << "DECLINED" << endl;
    }
  }
  cout << "RECAP: " << endl;
  for (int i = 0; i < ticket_sold; ++i) {
    cout << "TICKET No." << i + 1 << " , customer name: " << tickets[i].customer_name << ", number of tickets: " << tickets[i].number_of_tickets << endl;
  }
}
