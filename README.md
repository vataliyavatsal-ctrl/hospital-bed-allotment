# Hospital Bed & Patient Management System in C

A practical 2nd-year C console application designed to manage hospital bed allocations and patient admissions using File Handling.

## Features
- Admit new patients with specific bed numbers, names, ages, and ward categories
- Store patient data permanently in a local file (`hospital.txt`)
- Display a comprehensive list of all currently admitted patients
- Search for patient details instantly using their assigned Bed Number

## Concepts Covered
- **Structures (`struct`):** Custom records containing mixed data types (integers, strings)
- **File Handling:** Utilizing `fopen`, `fprintf`, `fscanf`, and `fclose` for data persistence
- **Control Flow:** `while(1)` infinite loop with `if-else if` menu routing
- **Search Logic:** Sequential scanning through file records to locate matching bed numbers

## How to Run
1. Compile the program:
   ```bash
   gcc main.c -o main