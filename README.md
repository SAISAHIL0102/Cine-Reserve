# 🎬Cine Reserve -> Movie Ticket Booking System 

Cine Reserve is a terminal-based movie ticket booking system designed using Object-Oriented Programming (OOP) principles.It manages movie listings, showtimes, customers, seating arrangements, and booking tickets with price calculations and receipt generation.

✅ Features

Object-Oriented Design with well-defined classes:
Seat, Movie, Show, Customer, Booking, Theater, and MovieBookingSystem
Seat Categories: VIP, Premium, Regular – each with distinct pricing.
Seat Status Tracking: Available, Reserved, Booked.
Dynamic Show Management with real-time updates.
User Input Validation for robust interaction.

Booking Receipt Generation with:
  Customer & Movie Details
  Tax & Service Fee Calculations (GST, service charge)
  ASCII-formatted ticket with summary
  
Booking Search by ID with optional reprinting of receipt.
Theater Statistics showing occupancy rate and revenue.
Persistent seat status within runtime session (via pointers).

🧱 Classes & Responsibilities

Class	                                   Responsibility
Seat	                  Models a seat in the theater (row, column, type, status, price)
Movie	                  Stores metadata about a film (title, genre, duration, rating)
Show	                  Represents a scheduled screening with a Movie, time, date, and show ID
Customer  	            Holds customer info (name, contact, ID)
Booking	                Manages the booked seats, generates invoice with tax/service fees
Theater	                Central hub for managing seats, bookings, shows, and displaying data
MovieBookingSystem    	Main app loop with menu-driven interaction and booking workflows

🧾 Receipt Format:

  The system prints a detailed receipt with:
    Booking ID and timestamp
    Customer details
    Movie/show details
    Seat info with category and pricing
    Subtotal, service charge (2%), GST (18%)
    Total amount

    
💻 Technologies Used

  Language: C++
  Libraries: iostream, vector, map, iomanip, ctime, string, etc.
  Design: OOP-based modular design
  Interface: Command Line Interface (CLI)

🛠️ How It Works

 Start the System – runs a menu-driven loop.
 View Shows – lists currently available showtimes and movies.
 View Seating – displays real-time grid with availability.
 Book Tickets – customer selects a show and desired seats.
 Generate Receipt – includes taxes, fees, and seat breakdown.
 Search Booking – by booking ID for confirmation or reprinting.
 View Stats – seats booked, occupancy %, revenue, etc.

 1. WELCOME PAGE & OPTIONS SELECTION
    

<img width="1202" height="267" alt="Screenshot 2025-07-31 235540" src="https://github.com/user-attachments/assets/5e67e247-1f58-41cb-a2ed-039b54ae190f" />


2. VIEW SHOWS












   <img width="409" height="748" alt="Screenshot 2025-08-01 002303" src="https://github.com/user-attachments/assets/1326dbb4-4f0e-4202-9452-6b0324e4cbfb" />

   

3. VIEW SEATING

  <img width="489" height="398" alt="image" src="https://github.com/user-attachments/assets/235dcd36-f908-4728-8220-95197b170c1a" />


4. TICKET BOOKING
   
   
    <img width="403" height="764" alt="image" src="https://github.com/user-attachments/assets/caeb0079-2d87-46cd-9af1-1cb2d38e56cb" />

   
   <img width="486" height="764" alt="image" src="https://github.com/user-attachments/assets/c4a9ab28-a65b-4d30-be6f-5d75c2e31ca9" />

   
   <img width="455" height="757" alt="image" src="https://github.com/user-attachments/assets/29753e02-30e3-494d-9b39-da9747c5e8fb" />

   
   <img width="491" height="302" alt="image" src="https://github.com/user-attachments/assets/51ce0526-081f-495b-96ed-b0bed04956c1" />

   
   <img width="472" height="289" alt="image" src="https://github.com/user-attachments/assets/3c410dcc-6f7e-42c8-bd1e-a53dd55a1017" />










   

6. Search Booking & Print Receipt


   <img width="480" height="685" alt="Screenshot 2025-08-01 002935" src="https://github.com/user-attachments/assets/8b5e8575-28f5-4868-ab23-19698eaef841" />
   
   




   
   

7. THEATER STATISTICS
   
     <img width="260" height="226" alt="image" src="https://github.com/user-attachments/assets/999f7974-f331-4c09-9f60-88ad9e3f603f" />




8. Closing

     

    <img width="383" height="244" alt="image" src="https://github.com/user-attachments/assets/d2f5660f-f4c9-4f08-b600-98084a868043" />
   





  

   






