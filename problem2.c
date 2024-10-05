#include <stdio.h>
#include <string.h>

// this function converts celsius to fahrenheit
float celsius_to_fahrenheit(float celsius) { 
    return ((9.0 / 5.0) * celsius) + 32; 
}

// this function converts fahrenheit to celsius
float fahrenheit_to_celsius(float fahrenheit) { 
    return (5.0 / 9.0) * (fahrenheit - 32); 
}

// this function converts celsius to kelvin
float celsius_to_kelvin(float celsius) { 
    return celsius + 273.15;
}

// this function converts kelvin to celsius
float kelvin_to_celsius(float kelvin) { 
    return kelvin - 273.15; 
}

// this function converts fahrenheit to kelvin
float fahrenheit_to_kelvin(float fahrenheit) { 
    return ((fahrenheit - 32) * (5.0 / 9.0)) + 273.15; 
}

// this function converts kelvin to fahrenheit
float kelvin_to_fahrenheit(float kelvin) { 
    return ((kelvin - 273.15) * (9.0 / 5.0)) + 32;
}

// this function categorizes the temperature and provides an advisory message
void categorize_temperature(float celsius) {
    // categorize category store
    char category[20]; 

    // initialize message store
    char advisory_msg[50]; 

    // map strings to category and advisory vars
    if (celsius < 0) {
        strcpy(category, "Freezing");
        strcpy(advisory_msg, "Stay indoors.");
    }
    else if (celsius >= 0 && celsius <= 10) {
        strcpy(category, "Cold");
        strcpy(advisory_msg, "Wear a jacket.");
    }
    else if (celsius > 10 && celsius <= 25) {
        strcpy(category, "Comfortable");
        strcpy(advisory_msg, "You should feel comfortable.");
    }
    else if (celsius > 25 && celsius <= 35) {
        strcpy(category, "Hot");
        strcpy(advisory_msg, "Dress light.");
    }
    else {
        strcpy(category, "Extreme Heat");
        strcpy(advisory_msg, "Stay indoors.");
    }

    // print the strings
    printf("Temperature category: %s\n", category); 
    printf("Weather advisory: %s\n", advisory_msg); 
}

// function to clear the input buffer
void clear_input_buffer() {
    int ch;

    // clear invalid input from buffer
    while ((ch = getchar()) != '\n' && ch != EOF);  
}

// main
int main() { 
    // declare vars
    float temp;
    float converted_temp;
    int current_scale; 
    int convert_to; 

    while (1) {
        // ask user for temp
        printf("Enter the temperature (numeric input): "); 

        // check if input is valid
        if (scanf("%f", &temp) != 1) { 
            printf("Invalid input! Please enter a valid number.\n");
            clear_input_buffer();  // clear buffer to avoid infinite loop
            continue;  // restart loop
        }

        // ask user for current scale
        printf("Enter the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: "); 
        
        // check if the input is valid 
        if (scanf("%d", &current_scale) != 1) { 
            printf("Invalid input! Please enter a valid scale (1, 2, or 3).\n");
            clear_input_buffer();
            continue;
        }

        // ask user for what to convert to
        printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: "); 
        
        // check if the input is valid
        if (scanf("%d", &convert_to) != 1) { 
            printf("Invalid input! Please enter a valid conversion scale (1, 2, or 3).\n");
            clear_input_buffer();
            continue;
        }

        // input is valid, so proceed to the logic
        // checking if kelvin is negative
        if (current_scale == 3 && temp < 0) { 
            printf("Kelvin temperature cannot be negative. Please try again.\n");
        }
        else if (current_scale == convert_to) { 
            printf("Cannot convert to current scale. Please try again.\n");
        }
        else { 
            // if all input is valid, break out of the loop
            break;
        }
    }

    // once out of the loop, convert
    if (current_scale == 1 && convert_to == 2) { 
        // celsius to fahrenheit
        converted_temp = celsius_to_fahrenheit(temp);
        printf("\nConverted temperature: %.2f degrees Fahrenheit\n", converted_temp);
        categorize_temperature(temp);
    }
    else if (current_scale == 1 && convert_to == 3) { 
        // celsius to kelvin
        converted_temp = celsius_to_kelvin(temp);
        printf("\nConverted temperature: %.2fK\n", converted_temp);
        categorize_temperature(temp);
    }
    else if (current_scale == 2 && convert_to == 1) { 
        // fahrenheit to celsius
        converted_temp = fahrenheit_to_celsius(temp);
        printf("\nConverted temperature: %.2f degrees Celsius\n", converted_temp);
        categorize_temperature(converted_temp);
    }
    else if (current_scale == 2 && convert_to == 3) { 
        // fahrenheit to kelvin
        converted_temp = fahrenheit_to_kelvin(temp);
        printf("\nConverted temperature: %.2fK\n", converted_temp);
        categorize_temperature(fahrenheit_to_celsius(temp));
    }
    else if (current_scale == 3 && convert_to == 1) { 
        // kelvin to celsius
        converted_temp = kelvin_to_celsius(temp);
        printf("\nConverted temperature: %.2f degrees Celsius\n", converted_temp);
        categorize_temperature(converted_temp);
    }
    else if (current_scale == 3 && convert_to == 2) { 
        // kelvin to fahrenheit
        converted_temp = kelvin_to_fahrenheit(temp);
        printf("\nConverted temperature: %.2f degrees Fahrenheit\n", converted_temp);
        categorize_temperature(kelvin_to_celsius(temp)); 
    }

    return 0;
}