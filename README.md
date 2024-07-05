This is the coursework of my MSE.800 Professional C++ Software Engineering. The reason of using the console
was it's required as this. So I did a OOP framework inside the command line, with the applicational 
layer for car rental features.


# YBCarRental
Car Rental Management system for Yoobee College (Software engineering project)
the design mind map locates:
https://miro.com/app/board/uXjVMvcJYG8=/


08/29/2023
Big step forward, the first view rendered!
![image](https://github.com/imadyTech/YBCarRental/assets/7894361/4e9fec20-ff95-4933-855e-c4aeac2540ea)

09/12/2023
Now the ListView is done!
![image](https://github.com/imadyTech/YBCarRental/assets/7894361/b12f8775-2feb-4280-bce5-2e0b17334dd1)

![image](https://github.com/imadyTech/YBCarRental/assets/7894361/e532c06d-4162-4818-8e56-82cf57c32eaf)





Car Rental Management System

-	User Manual (this is actuall a part of my submission required by the course program) -

1.	Contents
1.	Contents	1
2.	Introduction	3
3.	System Requirements and Installation	4
3.1.	System Requirements	4
3.2.	Installation Guide	4
3.3.	Launching the Application	4
3.4.	Uninstalling the Application	5
4.	Keyboard Operation Guide	5
5.	Main menu	6
5.1.	User Registration	6
5.2.	User Login	6
5.3.	Brief User Manual	7
6.	Car Management (For Admins)	7
6.1.	File Database	7
6.2.	Car Information Management	7
6.1.	Order Management	10
6.2.	User Management	12
7.	Customer User Features	13
7.1.	My Profile and account balance	13
7.2.	My Orders	14
7.3.	Rent a Car	15
8.	Licensing	16
8.1.	License Overview	16
8.2.	Permitted Usage	17
8.3.	Restricted Usage	17
8.4.	Commercial Licensing	17
8.5.	Disclaimer	17
9.	Reporting Issues	18
10.	Summary	19


 

2.	Introduction
Welcome to the Car Rental Management System! 
The Car Rental Management System is developed upon a multi-layer architecture with proprietary YBConsoleView, YBPersistence and YBCarRental libraries. It is a good reference for learning how to build an application framework to study the concept of OOP, abstracting, design patterns, data operations, and so much knowledge of C++ programming. 

This user manual will guide you through the various features and functionalities of our system. This software is designed to simplify the process of renting cars and managing car rental operations. Whether you're a customer looking to rent a car or an admin responsible for managing the fleet, this guide will help you get started.

 
For guides of further application development and framework extension, please like our open source project on https://github.com/imadyTech/YBCarRental for development guide and references.
 

3.	System Requirements and Installation

3.1.	System Requirements
Before installing the Car Rental System on your Windows computer, please ensure that your system meets the following minimum requirements:
Description	Requirement
Operating System	 Windows 10 (64-bit) or later.
Processor	 2.0 GHz dual-core processor or equivalent.
Memory (RAM)	 4 GB of RAM or more.
Storage	 200 MB of available hard disk space.
Display	 A screen resolution of 1280x768 pixels or higher.
Internet Connection	 NO internet connection is required for application runtime.
Input Devices	 Only Keyboard.

3.2.	Installation Guide
Follow these steps to install the Yoobee Car Rental System on your Windows computer:
1. Download the Installer:
- Visit our official website (https://www.yoobeecarrental.com... oh this actually is a pyeudo web... never try) to download the latest version of the Yoobee Car Rental System installer for Windows.
2. Unpack the Installer zip file:
- Locate the downloaded installer file (usually in your Downloads folder) and unpack it to any directory you like.
4. License Agreement:
- There is not End User License Agreement (EULA) during the installation process. The User Manual is included in the installation package and has a license part in it. You agree to abide the License Agreement by unpacking the installation package.

3.3.	Launching the Application
To start using the Car Rental System, locate the program directory in your file explorer and double-click the CarRental.exe to launch the application.

3.4.	Uninstalling the Application
To uninstall, simply delete the whole installation directory and nothing left on your computer.




4.	Keyboard Operation Guide
Not all keys from the keyboard will be functional in the Car Rental System. As the Car Rental System is a text-based software, it provides pure keyboard operation and does NOT support mouse operation. Follow the following guide for better operations:
Use 'Tab' Key to Toggle Inputs and Buttons
- Use the 'Tab' key to navigate through input fields and buttons. You will see the current active item (Inputs or Button) will be highlighted.
Use 'Return' Key to Confirm or Submit
- When you've filled out a form or made a selection, you can press the 'Return' key to confirm your choice and submit the form
Use 'Esc' Key to Go Back to the Main Menu View
- Press the 'Esc' key to return to the main memu view. This is handy when you want to repeat some functions without quit the application.
Use Alphabets and Numbers to Input Information
- When prompted to input information, you can use your keyboard to type alphabetic characters and numbers. This is especially useful for text fields, such as your name, email, or other details.
Use the Back Arrow to Modify Some Input
- If you need to correct or modify previously entered information, look for a back arrow, typically represented as a left-pointing arrow. Selecting this option allows you to make changes to your input.

By utilizing these keyboard shortcuts and operations, you can navigate and interact with the Yoobee Car Rental System more efficiently. These shortcuts are designed to save you time and make your experience smoother.



5.	Main menu
The main menu is the entrance of the Car Rental System. You may register a new user and login, then you will be led to the user main menu. If you successfully log in with an admin account, then you will be automatically redirected to the admin main menu which provides different features to normal user.
Ask the administrator for the information of admin account. The admin role could only be authorized by modifying the database with super administrator power.
 
5.1.	User Registration
To use the system, users must first register. Follow these steps:
1.	Access the system's registration page.
2.	Fill out the registration form with your personal information.
3.	Click the "Register" button to create your account.

5.2.	User Login
After registration, follow these steps to log in:
1.	Access the system's login page.
2.	Enter your registered email and password.
3.	Click the "Login" button to access your account.

5.3.	Brief User Manual
This provides a brief description of the keyboard operations.





6.	Car Management (For Admins)

6.1.	File Database
The system maintains a file-based database of available cars, users, and orders. Please make sure the following database files are included in the same directory of the executable (.exe file) application file:
Contact your administrator if you having trouble to locate the database files and cause to an error when executing the Car Rental System.
Type of database	File Storage 
Car information database	CarRepo.txt
User information database	UserRepo.txt
Rental orders database	RentRepo.txt


6.2.	Car Information Management
Only Admin User have the privilege to manage records of cars.
•Adding a Car: 
To add a new car to the database, follow these steps:
1.	Log in as an admin.
2.	Access the admin dashboard.
3.	Choose the "Add Car" option.
4.	Fill in the car details.
5.	Click the "Add" button.
 
•Updating a Car
To update car information, follow these steps:
1.	Log in as an admin.
2.	Access the admin dashboard.
3.	List and choose the car you want to update.
 
4.	Modify the car details (use Tab to toggle the value input fields and UPDATE button).
 
5.	Click the "Update Car" button.
•Deleting a Car
To remove a car from the database, follow these steps:
1.	Log in as an admin.
2.	Access the admin dashboard.
3.	Choose the car you want to delete.
 
4.	Click the "Delete" button and confirm deleting.

6.1.	Order Management
Users with admin authentication have the privilege to approve or reject rental orders. To approve or reject an order, follow these steps:
1.	Log in as an admin.
2.	Access the admin dashboard.
3.	Choose the order management function.
4.	From the order list, choose the order you want approve or reject.

  
4.	Review the details of the order, and then choose to approve or reject the order by clicking “APPROVE” or “REJECT” button.
 
5. 	Confirm the action.
 

6.2.	User Management
Only users authorized as admin have the privilege to update the user information, include the account balance of the user.
Be extreme cautious when updating the user information.
 
 
The system does not support the user DELETION at this moment as it endangers the system with unknown risk.
7.	Customer User Features
If you log in with a user account (you create account through user registration), you will be directed to the user menu automatically after login.  
 

7.1.	My Profile and account balance
You may review your account information include the balance in your account. Unfortunately, there is no online top-up features available at this moment, ask the administrator for topping up.
 
7.2.	My Orders
Reviewing all your rental orders list in this view. 
 
Move with the Tab key and enter to check the order details.
 
7.3.	Rent a Car
Customers can view available cars and their details by following these steps:
1.	Log in as a customer.
2.	Access the customer dashboard.
3.	Browse through the list of available cars by “Rent a car” menu.
 
4.	Click on a car to see its details.

 
Our system calculates rental fees based on the selected car, rental duration, and any additional charges. The final rental fee will be displayed before confirming the booking. The order won’t be successful if your account balance is insufficient.
Users with administrator role have the responsibility to manage rental bookings, including approving or rejecting requests. This can be done through the admin dashboard.



8.	Licensing

The Car Rental System is licensed under the terms of the [Car Rental Open Source License](https://github.com/imadyTech/YBCarRental/blob/main/LICENSE).

8.1.	License Overview
The copyright of all texts, images, code, released software product, and the scheme of YBML of the Car Rental System belongs to the author and is offered as open-source software, allowing for free usage by individuals and non-profit organizations. However, the following licensing terms apply:
8.2.	Permitted Usage
- **Individuals**: Individuals are permitted to use the Car Rental System for personal or educational purposes free of charge.
- **Non-Profit Organizations**: Non-profit organizations, including educational institutions, charities, and non-governmental organizations, are granted free usage of the Car Rental System.

8.3.	Restricted Usage
The following types of organizations are not eligible for free usage of the Car Rental System and must obtain a separate commercial license:
- **Profitable Organizations**: Profitable organizations, including businesses and corporations, must obtain a commercial license for usage.
- **Governmental Institutes**: Military and Governmental institutes at the federal, state, or local levels must obtain a commercial license for usage.
For other type of users, please contact the author for usage permission.

8.4.	Commercial Licensing
For profitable organizations and governmental institutes interested in using the Car Rental System, please contact us to inquire about obtaining a commercial license. Commercial licenses are subject to terms and conditions that differ from those of open-source usage.

8.5.	Disclaimer
The Car Rental System is provided "as is," without warranty of any kind, express or implied. The developers and contributors to the project are not responsible for any damages or liabilities arising from the use of the software.
By using the Car Rental System, you agree to abide by the terms of the [Car Rental Open Source License](https://github.com/imadyTech/YBCarRental/blob/main/LICENSE).



9.	Reporting Issues
We value your feedback and aim to continuously improve the Car Rental System. 
If you encounter an issue that is not resolved through this troubleshooting guide, or if you have suggestions for enhancements, please report them on our GitHub repository: https://github.com/imadyTech/YBCarRental

When reporting issues, be sure to provide the following details:
- A clear description of the problem
- Steps to reproduce the issue
- Any error messages received
- Screenshots (if applicable)
- Your system environment (e.g., browser, operating system)

Our development team (yes, me only) will review your feedback and work towards resolving any reported issues promptly. Thank you for helping us improve the Car Rental System.

 

10.	Summary
This user manual provides an overview of the Car Rental Management System's key features and functionalities. Whether you're a customer or an admin, we hope this guide helps you effectively use our system to rent cars and manage your rental operations. If you encounter any issues or have questions, please reach out to our support team for assistance. Thank you for choosing our Car Rental Management System!
 
Copyright © Zhenqun Shen, 2023
Splash Design - Ann and Grace
Yoobee College of Creative Innovation
