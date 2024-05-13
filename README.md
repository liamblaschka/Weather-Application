# Weather-Application

Overview

The Weather Application is a user-friendly application that provides accurate weather infomation to the user through a user-friendly interface. The weather application 
can forecast the weather for the users location up to 7 days and provide the temperature and rain chance for every one of those days. When the app is first opened the app is able to locate the users location and provide weather information for their respective location and users can view all weather information for all Australian capital cities. This application leverages various APIs and data sources to deliver real-time weather updates.a


Features
- Current Weather: View current weather conditions including temperature and rain chance
- Forecast: Provide a detailed weather forecast infromation for the next 7 days including the high and low temperatures and rain chance
- Saved Locations: Save frequently visited locations to save locations list to easily access their weather information
- Delete Saved Locations: Delete a location off the location list to choose other cities to put on the list.a

Technlogies Used
- Programming Language: C++
- APIs: [openweathermap api]
- Libraries:[SFML, curl, nlohmann json]

How to use
- to compile type make release into terminal then to run type ./bin/release
- answer question in terminal asking if you allow the appliation to use your location
- see weather forcast on main page and if wanting to chance the location or save locations click top left on the city
- Add and delete locations to the saved locations or delete them by clicking on the bin icon and select the location not desired


Create a build directory, in terminal run cmake .., then run make, then in bin run ./weather

![alt text](https://github.com/liamblaschka/image-repo/blob/main/Weather-Application/user_location.png)
![alt text](https://github.com/liamblaschka/image-repo/blob/main/Weather-Application/select_location.png)
