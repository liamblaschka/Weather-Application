# Weather-Application
C++ weather application using the SFML library

This weather application was made as a group project for my Object Oriented Programming course at The University of Adelaide in 2023.
The program at first displays the weather of the user's location according to their IP, the user can then click on the locaiton to open a menu where they can save locations to a list of 5 locations, choosing from any Australian capital city, this list is saved in a .txt file so the user can access their saved locations when they run the program again. The user can add, remove, or drag and drop to change the order of the locations.

The current temperature and weather icon, as well as the next 7 day forecasted weather with their temperatures, weather icons and chance of rain for the selected locaiton are displayed.
All weather information is sourced from the Open Weather Map API and is refreshed for the selected location every 30 seconds.
