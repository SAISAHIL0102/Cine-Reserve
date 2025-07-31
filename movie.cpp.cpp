#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iomanip>
#include <algorithm>
#include <ctime>
#include <sstream>
#include <limits>

using namespace std;

// Enum for seat types
enum class SeatType {
    REGULAR,
    PREMIUM,
    VIP
};

// Enum for seat status
enum class SeatStatus {
    AVAILABLE,
    RESERVED,
    BOOKED
};

// Seat class
class Seat {
private:
    int row, col;
    SeatType type;
    SeatStatus status;
    double price;
    
public:
    Seat(int r, int c, SeatType t, double p) 
        : row(r), col(c), type(t), status(SeatStatus::AVAILABLE), price(p) {}
    
    // Getters
    int getRow() const { return row; }
    int getCol() const { return col; }
    SeatType getType() const { return type; }
    SeatStatus getStatus() const { return status; }
    double getPrice() const { return price; }
    string getSeatId() const { 
        return string(1, 'A' + row) + to_string(col + 1); 
    }
    
    // Setters
    void setStatus(SeatStatus s) { status = s; }
    void setPrice(double p) { price = p; }
    
    // Utility methods
    bool isAvailable() const { return status == SeatStatus::AVAILABLE; }
    string getTypeString() const {
        switch(type) {
            case SeatType::REGULAR: return "Regular";
            case SeatType::PREMIUM: return "Premium";
            case SeatType::VIP: return "VIP";
            default: return "Unknown";
        }
    }
    
    char getDisplayChar() const {
        switch(status) {
            case SeatStatus::AVAILABLE: return 'O';
            case SeatStatus::RESERVED: return 'R';
            case SeatStatus::BOOKED: return 'X';
            default: return '?';
        }
    }
};

// Movie class
class Movie {
private:
    string title;
    string genre;
    int duration; // in minutes
    string rating;
    
public:
    Movie(string t, string g, int d, string r) 
        : title(t), genre(g), duration(d), rating(r) {}
    
    // Getters
    string getTitle() const { return title; }
    string getGenre() const { return genre; }
    int getDuration() const { return duration; }
    string getRating() const { return rating; }
    
    void displayInfo() const {
        cout << "Title: " << title << endl;
        cout << "Genre: " << genre << endl;
        cout << "Duration: " << duration << " minutes" << endl;
        cout << "Rating: " << rating << endl;
    }
};

// Show class
class Show {
private:
    Movie movie;
    string showTime;
    string showDate;
    int showId;
    
public:
    Show(Movie m, string time, string date, int id) 
        : movie(m), showTime(time), showDate(date), showId(id) {}
    
    // Getters
    Movie getMovie() const { return movie; }
    string getShowTime() const { return showTime; }
    string getShowDate() const { return showDate; }
    int getShowId() const { return showId; }
    
    void displayShowInfo() const {
        cout << "Show ID: " << showId << endl;
        cout << "Date: " << showDate << " | Time: " << showTime << endl;
        movie.displayInfo();
    }
};

// Customer class
class Customer {
private:
    string name;
    string phone;
    string email;
    int customerId;
    
public:
    Customer(string n, string p, string e, int id) 
        : name(n), phone(p), email(e), customerId(id) {}
    
    // Getters
    string getName() const { return name; }
    string getPhone() const { return phone; }
    string getEmail() const { return email; }
    int getCustomerId() const { return customerId; }
    
    void displayInfo() const {
        cout << "Customer: " << name << endl;
        cout << "Phone: " << phone << endl;
        cout << "Email: " << email << endl;
    }
};

// Booking class
class Booking {
private:
    int bookingId;
    Customer customer;
    Show show;
    vector<Seat*> bookedSeats;
    double totalAmount;
    string bookingTime;
    
public:
    Booking(int id, Customer c, Show s) 
        : bookingId(id), customer(c), show(s), totalAmount(0.0) {
        // Get current time
        time_t now = time(0);
        bookingTime = ctime(&now);
        bookingTime.pop_back(); // Remove newline
    }
    
    void addSeat(Seat* seat) {
        bookedSeats.push_back(seat);
        totalAmount += seat->getPrice();
    }
    
    // Getters
    int getBookingId() const { return bookingId; }
    Customer getCustomer() const { return customer; }
    Show getShow() const { return show; }
    vector<Seat*> getBookedSeats() const { return bookedSeats; }
    double getTotalAmount() const { return totalAmount; }
    string getBookingTime() const { return bookingTime; }
    
    void displayBookingDetails() const {
        cout << "\n=== BOOKING CONFIRMATION ===" << endl;
        cout << "Booking ID: " << bookingId << endl;
        cout << "Booking Time: " << bookingTime << endl;
        cout << "\nCustomer Details:" << endl;
        customer.displayInfo();
        cout << "\nShow Details:" << endl;
        show.displayShowInfo();
        cout << "\nBooked Seats:" << endl;
        for(const auto& seat : bookedSeats) {
            cout << "Seat " << seat->getSeatId() 
                 << " (" << seat->getTypeString() << ") - Rs." 
                 << seat->getPrice() << endl;
        }
        cout << "\nTotal Amount: Rs." << totalAmount << endl;
        cout << "=============================" << endl;
    }
    
    void printReceipt() const {
        cout << "\n";
        cout << "************************************************" << endl;
        cout << "*                                              *" << endl;
        cout << "*            CINEPLEX THEATER                  *" << endl;
        cout << "*             TICKET RECEIPT                  *" << endl;
        cout << "*                                              *" << endl;
        cout << "************************************************" << endl;
        cout << endl;
        
        // Receipt Header
        cout << "Receipt No: " << bookingId << endl;
        cout << "Date & Time: " << bookingTime << endl;
        cout << "________________________________________________" << endl;
        cout << endl;
        
        // Customer Information
        cout << "CUSTOMER DETAILS:" << endl;
        cout << "Name        : " << customer.getName() << endl;
        cout << "Phone       : " << customer.getPhone() << endl;
        cout << "Email       : " << customer.getEmail() << endl;
        cout << "Customer ID : " << customer.getCustomerId() << endl;
        cout << "________________________________________________" << endl;
        cout << endl;
        
        // Movie & Show Information
        cout << "SHOW DETAILS:" << endl;
        cout << "Movie       : " << show.getMovie().getTitle() << endl;
        cout << "Genre       : " << show.getMovie().getGenre() << endl;
        cout << "Duration    : " << show.getMovie().getDuration() << " mins" << endl;
        cout << "Rating      : " << show.getMovie().getRating() << endl;
        cout << "Show Date   : " << show.getShowDate() << endl;
        cout << "Show Time   : " << show.getShowTime() << endl;
        cout << "Show ID     : " << show.getShowId() << endl;
        cout << "________________________________________________" << endl;
        cout << endl;
        
        // Seat Details
        cout << "TICKET DETAILS:" << endl;
        cout << left << setw(8) << "Seat" 
             << setw(12) << "Type" 
             << setw(10) << "Price" << endl;
        cout << "--------------------------------" << endl;
        
        double subtotal = 0.0;
        for(const auto& seat : bookedSeats) {
            cout << left << setw(8) << seat->getSeatId()
                 << setw(12) << seat->getTypeString()
                 << "Rs." << setw(7) << fixed << setprecision(2) << seat->getPrice() << endl;
            subtotal += seat->getPrice();
        }
        
        cout << "--------------------------------" << endl;
        cout << "Number of Tickets: " << bookedSeats.size() << endl;
        cout << "Subtotal         : Rs." << fixed << setprecision(2) << subtotal << endl;
        
        // Calculate taxes and fees
        double serviceFee = subtotal * 0.02; // 2% service fee
        double gst = subtotal * 0.18; // 18% GST
        double total = subtotal + serviceFee + gst;
        
        cout << "Service Fee (2%) : Rs." << fixed << setprecision(2) << serviceFee << endl;
        cout << "GST (18%)        : Rs." << fixed << setprecision(2) << gst << endl;
        cout << "--------------------------------" << endl;
        cout << "TOTAL AMOUNT     : Rs." << fixed << setprecision(2) << total << endl;
        cout << "================================" << endl;
        cout << endl;
        
        // Important Information
        cout << "IMPORTANT INFORMATION:" << endl;
        cout << "• Please arrive 15 minutes before show time" << endl;
        cout << "• Carry a valid ID proof" << endl;
        cout << "• Outside food & beverages not allowed" << endl;
        cout << "• No refunds or exchanges" << endl;
        cout << "• Keep this receipt for entry" << endl;
        cout << endl;
        
        // Footer
        cout << "************************************************" << endl;
        cout << "*     Thank you for choosing Cineplex!        *" << endl;
        cout << "*        Have a great movie experience!        *" << endl;
        cout << "************************************************" << endl;
        cout << endl;
        
        // Update total amount with taxes
        const_cast<Booking*>(this)->totalAmount = total;
    }
};

// Theater class
class Theater {
private:
    string name;
    vector<vector<Seat>> seats;
    int rows, cols;
    vector<Show> shows;
    vector<Booking> bookings;
    int nextBookingId;
    
    void initializeSeats() {
        seats.resize(rows, vector<Seat>());
        
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                SeatType type;
                double price;
                
                // VIP seats (first 2 rows)
                if(i < 2) {
                    type = SeatType::VIP;
                    price = 300.0;
                }
                // Premium seats (next 3 rows)
                else if(i < 5) {
                    type = SeatType::PREMIUM;
                    price = 200.0;
                }
                // Regular seats (remaining rows)
                else {
                    type = SeatType::REGULAR;
                    price = 150.0;
                }
                
                seats[i].emplace_back(i, j, type, price);
            }
        }
    }
    
public:
    Theater(string n, int r, int c) 
        : name(n), rows(r), cols(c), nextBookingId(1001) {
        initializeSeats();
    }
    
    void addShow(const Show& show) {
        shows.push_back(show);
    }
    
    // Get number of shows - FIXED: Added this method
    int getShowCount() const {
        return shows.size();
    }
    
    void displaySeatingGrid() const {
        cout << "\n=== SEATING ARRANGEMENT ===" << endl;
        cout << "Legend: O = Available, R = Reserved, X = Booked" << endl;
        cout << "VIP (Rs.300) | Premium (Rs.200) | Regular (Rs.150)" << endl;
        cout << "\n    ";
        
        // Column numbers
        for(int j = 0; j < cols; j++) {
            cout << setw(3) << (j + 1);
        }
        cout << endl;
        
        for(int i = 0; i < rows; i++) {
            cout << char('A' + i) << "   ";
            for(int j = 0; j < cols; j++) {
                cout << setw(3) << seats[i][j].getDisplayChar();
            }
            
            // Show seat type for each row
            cout << "  (";
            if(i < 2) cout << "VIP";
            else if(i < 5) cout << "Premium";
            else cout << "Regular";
            cout << ")" << endl;
        }
        cout << "\n        SCREEN" << endl;
        cout << "=========================" << endl;
    }
    
    void displayShows() const {
        cout << "\n=== AVAILABLE SHOWS ===" << endl;
        for(size_t i = 0; i < shows.size(); i++) {
            cout << "\n" << (i + 1) << ". ";
            shows[i].displayShowInfo();
            cout << "------------------------" << endl;
        }
    }
    
    bool bookSeats(int showIndex, const vector<string>& seatIds, const Customer& customer) {
        if(showIndex < 0 || showIndex >= (int)shows.size()) {
            cout << "Invalid show selection! Available shows: 1-" << shows.size() << endl;
            return false;
        }
        
        vector<Seat*> seatsToBook;
        
        // Validate all seats first
        for(const string& seatId : seatIds) {
            Seat* seat = findSeat(seatId);
            if(!seat) {
                cout << "Invalid seat: " << seatId << endl;
                return false;
            }
            if(!seat->isAvailable()) {
                cout << "Seat " << seatId << " is not available!" << endl;
                return false;
            }
            seatsToBook.push_back(seat);
        }
        
        // Book all seats
        Booking booking(nextBookingId++, customer, shows[showIndex]);
        for(Seat* seat : seatsToBook) {
            seat->setStatus(SeatStatus::BOOKED);
            booking.addSeat(seat);
        }
        
        bookings.push_back(booking);
        
        // Print detailed receipt
        cout << "\n🎫 PRINTING RECEIPT... 🎫" << endl;
        booking.printReceipt();
        
        // Ask if user wants a copy
        char choice;
        cout << "Would you like to save this receipt? (y/n): ";
        cin >> choice;
        cin.ignore(); // FIXED: Clear the input buffer
        if(choice == 'y' || choice == 'Y') {
            cout << "Receipt saved! (In a real system, this would save to file)" << endl;
        }
        
        return true;
    }
    
    Seat* findSeat(const string& seatId) {
        if(seatId.length() < 2) return nullptr;
        
        int row = seatId[0] - 'A';
        int col = stoi(seatId.substr(1)) - 1;
        
        if(row < 0 || row >= rows || col < 0 || col >= cols) {
            return nullptr;
        }
        
        return &seats[row][col];
    }
    
    void displayBookings() const {
        cout << "\n=== ALL BOOKINGS ===" << endl;
        if(bookings.empty()) {
            cout << "No bookings found." << endl;
            return;
        }
        
        for(size_t i = 0; i < bookings.size(); i++) {
            cout << "\n" << (i + 1) << ". ";
            bookings[i].displayBookingDetails();
            cout << endl;
        }
    }
    
    void searchBooking(int bookingId) const {
        for(const auto& booking : bookings) {
            if(booking.getBookingId() == bookingId) {
                cout << "\n📋 Booking Found!" << endl;
                booking.displayBookingDetails();
                
                // Ask if user wants to print receipt
                char choice;
                cout << "\nWould you like to print the receipt? (y/n): ";
                cin >> choice;
                cin.ignore(); // FIXED: Clear the input buffer
                if(choice == 'y' || choice == 'Y') {
                    cout << "\n🎫 PRINTING RECEIPT... 🎫" << endl;
                    booking.printReceipt();
                }
                return;
            }
        }
        cout << "❌ Booking not found!" << endl;
    }
    
    void displayStats() const {
        int totalSeats = rows * cols;
        int bookedSeats = 0;
        double totalRevenue = 0.0;
        
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(seats[i][j].getStatus() == SeatStatus::BOOKED) {
                    bookedSeats++;
                }
            }
        }
        
        for(const auto& booking : bookings) {
            totalRevenue += booking.getTotalAmount();
        }
        
        cout << "\n=== THEATER STATISTICS ===" << endl;
        cout << "Theater: " << name << endl;
        cout << "Total Seats: " << totalSeats << endl;
        cout << "Booked Seats: " << bookedSeats << endl;
        cout << "Available Seats: " << (totalSeats - bookedSeats) << endl;
        cout << "Occupancy Rate: " << fixed << setprecision(1) 
             << (double(bookedSeats) / totalSeats * 100) << "%" << endl;
        cout << "Total Revenue: Rs." << totalRevenue << endl;
        cout << "Total Bookings: " << bookings.size() << endl;
        cout << "=========================" << endl;
    }
};

// Main application class
class MovieBookingSystem {
private:
    Theater theater;
    
    void displayMenu() const {
        cout << "\n===== MOVIE BOOKING SYSTEM =====" << endl;
        cout << "1. View Shows" << endl;
        cout << "2. View Seating Arrangement" << endl;
        cout << "3. Book Tickets" << endl;
        cout << "4. View All Bookings" << endl;
        cout << "5. Search Booking & Print Receipt" << endl;
        cout << "6. Theater Statistics" << endl;
        cout << "7. Exit" << endl;
        cout << "=================================" << endl;
        cout << "Enter your choice: ";
    }
    
    // FIXED: Added input validation helper
    int getValidatedInput(int min, int max) {
        int input;
        while(true) {
            if(cin >> input) {
                if(input >= min && input <= max) {
                    return input;
                } else {
                    cout << "Please enter a number between " << min << " and " << max << ": ";
                }
            } else {
                cout << "Invalid input! Please enter a number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    }
    
    Customer getCustomerDetails() const {
        string name, phone, email;
        cout << "\nEnter customer details:" << endl;
        cout << "Name: ";
        cin.ignore(); // FIXED: Clear input buffer before getline
        getline(cin, name);
        cout << "Phone: ";
        getline(cin, phone);
        cout << "Email: ";
        getline(cin, email);
        
        return Customer(name, phone, email, rand() % 9000 + 1000);
    }
    
public:
    MovieBookingSystem() : theater("Cineplex Theater", 8, 10) {
        // Initialize with some sample shows
        Movie movie1("Avengers: Endgame", "Action/Adventure", 181, "9.5");
        Movie movie2("The Lion King", "Animation/Family", 118, "8.8");
        Movie movie3("Joker", "Crime/Drama", 122, "8.5");
        
        theater.addShow(Show(movie1, "10:00 AM", "2024-01-15", 101));
        theater.addShow(Show(movie1, "02:00 PM", "2024-01-15", 102));
        theater.addShow(Show(movie2, "11:00 AM", "2024-01-15", 103));
        theater.addShow(Show(movie3, "06:00 PM", "2024-01-15", 104));
    }
    
    void run() {
        srand(time(nullptr));
        int choice;
        
        cout << "Welcome to CINE RESERVE!" << endl;
        
        while(true) {
            displayMenu();
            choice = getValidatedInput(1, 7); // FIXED: Use validated input
            
            switch(choice) {
                case 1:
                    theater.displayShows();
                    break;
                    
                case 2:
                    theater.displaySeatingGrid();
                    break;
                    
                case 3: {
                    theater.displayShows();
                    int showCount = theater.getShowCount(); // FIXED: Dynamic show count
                    cout << "\nSelect show number (1-" << showCount << "): ";
                    int showChoice = getValidatedInput(1, showCount); // FIXED: Use validated input
                    
                    theater.displaySeatingGrid();
                    
                    cout << "\nHow many seats do you want to book? ";
                    int numSeats = getValidatedInput(1, 10); // FIXED: Reasonable max limit
                    
                    vector<string> seatIds;
                    cout << "Enter seat IDs (e.g., A1, B5): ";
                    cin.ignore(); // FIXED: Clear input buffer
                    for(int i = 0; i < numSeats; i++) {
                        string seatId;
                        cin >> seatId;
                        transform(seatId.begin(), seatId.end(), seatId.begin(), ::toupper);
                        seatIds.push_back(seatId);
                    }
                    
                    Customer customer = getCustomerDetails();
                    theater.bookSeats(showChoice - 1, seatIds, customer);
                    break;
                }
                
                case 4:
                    theater.displayBookings();
                    break;
                    
                case 5: {
                    cout << "Enter booking ID: ";
                    int bookingId = getValidatedInput(1000, 9999); // FIXED: Use validated input
                    theater.searchBooking(bookingId);
                    break;
                }
                
                case 6:
                    theater.displayStats();
                    break;
                    
                case 7:
                    cout << "Thank you for using Movie Booking System!" << endl;
                    return;
                    
                default:
                    cout << "Invalid choice! Please try again." << endl;
            }
        }
    }
};

int main() {
    MovieBookingSystem system;
    system.run();
    return 0;
}