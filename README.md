# Ceremony Seat Management System


---

# README

## i. Short Intro
The Ceremony Seat Management System helps manage seating arrangements efficiently. Users can reserve seats, cancel bookings, and store seating data using file handling.

---

## ii. Used Technologies
- C Programming Language
- Structures (`struct`)
- File Handling
- Arrays
- Loops & Conditional Statements

### Libraries Used
- `stdio.h`
- `string.h`

---

## iii. Features

### User Can:
- Create seating arrangements
- Book seats
- Cancel reservations
- Update guest details
- Save seating data
- Load saved data

### Keyboard Inputs

| Action | Input |
|---|---|
| Book Seat | `1` |
| Cancel Booking | `2` |
| Update Booking | `3` |
| Save Data | `4` |
| Load Data | `5` |
| Exit Program | `6` |

---

## iv. The Process
1. Created a `Seat` structure.
2. Used a 2D array for seat positions.
3. Implemented menu-driven operations.
4. Added file handling for saving/loading data.
5. Added validation checks.

---

## v. What I Learned
- Structures and arrays in C
- Binary file handling
- Menu-driven programming
- Input validation

---

## vi. Future Improvements
- Admin authentication
- GUI support
- Dynamic seating system
- Search functionality
- Booking history

---

## vii. How to Run

### Compile
```bash
gcc seat_management.c -o seat_management
```

### Run
```bash
./seat_management
```
