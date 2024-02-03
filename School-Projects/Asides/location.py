# First Intall geopy (pip install geopy)

from geopy.geocoders import Nominatim

# Creating the Geolocator object with a user-agent
geolocator = Nominatim(user_agent="geoapiExercises")

# Get name of city
city_name = input("Enter the name of the city: ")

# Geocode city address to find its location on earth
location = geolocator.geocode(city_name)

print(
    f"The coordinates for {city_name} are latitude:{location.latitude}, longitude:{location.longitude}")
