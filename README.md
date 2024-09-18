# Custom Calendar Management System

## Project Overview

This project implements a custom calendar system that allows users to manage their schedules in July 2024. Users can:
- Add, delete, and view events.
- Manage daily, weekly, and monthly schedules.
- Validate event times and dates to ensure proper scheduling.

The project consists of three main components:
- **`calander.cpp`**: Handles the main calendar functionalities.
- **`days.cpp`**: Manages individual days in the calendar.
- **`events.cpp`**: Manages event creation, deletion, and display.

## Features
- **Add Events**: Supports adding singular, daily repeating, weekly repeating events, or marking a day off.
- **Delete Events**: Allows deletion of scheduled events by title and time.
- **View Schedule**: View the schedule for a specific day, a week, or the entire month.
- **Date and Time Validation**: Ensures that event times are in a valid 24-hour format and within the allowed dates (July 2024).
  
## File Descriptions
- **`main.cpp`**: The entry point of the program. It handles user input, displays menus, and interacts with other components to perform actions.
- **`calander.cpp`**: Implements the logic for booking and managing events across the days of July.
- **`days.cpp`**: Provides functionality to manage individual days and store event data.
- **`events.cpp`**: Deals with creating, storing, and managing event objects.

## How to Use
To compile and run the application, use C++ compiler that supports C++11 or later,
using g++;
g++ main.cpp calander.cpp days.cpp events.cpp -o calendar
./calendar
