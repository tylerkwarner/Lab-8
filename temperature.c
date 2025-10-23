include <stdio.h>
#include <ctype.h>


double toCelsius(double temp, char scale) {
    switch (toupper(scale)) {
        case 'C': return temp;
        case 'F': return (temp - 32) * 5.0 / 9.0;
        case 'K': return temp - 273.15;
        default: return 0.0; 
    }
}

double fromCelsius(double tempC, char scale) {
    switch (toupper(scale)) {
        case 'C': return tempC;
        case 'F': return tempC * 9.0 / 5.0 + 32;
        case 'K': return tempC + 273.15;
        default: return 0.0; 
}

const char* categorize(double tempC) {
    if (tempC < 0) return "Freezing";
    else if (tempC < 10) return "Cold";
    else if (tempC < 25) return "Comfortable";
    else if (tempC < 35) return "Hot";
    else return "Extreme Heat";
}

const char* advisory(const char* category) {
    if (category == NULL) return "";
    if (category[0] == 'F') return "Wear a heavy coat!";
    if (category[0] == 'C') return "Wear a jacket.";
    if (category[0] == 'H') return "Drink lots of water!";
    if (category[0] == 'E') return "Stay indoors and avoid heat.";
    return "Enjoy the weather!";
}

int main(void) {
    double temp;
    char from, to;

    printf("Enter the temperature value: ");
    if (scanf("%lf", &temp) != 1) {
        printf("Invalid temperature input.\n");
        return 1;
    }

    printf("Enter the original scale (C, F, or K): ");
    scanf(" %c", &from);

    printf("Enter the scale to convert to (C, F, or K): ");
    scanf(" %c", &to);

    from = toupper(from);
    to = toupper(to);

    if ((from != 'C' && from != 'F' && from != 'K') ||
        (to != 'C' && to != 'F' && to != 'K')) {
        printf("Invalid scale entered. Use C, F, or K.\n");
        return 1;
    }

    
    double tempC = toCelsius(temp, from);
    if (from == 'K' && temp < 0) {
        printf("Invalid temperature: Kelvin cannot be negative.\n");
        return 1;
    }

   
    double result = fromCelsius(tempC, to);

    printf("Converted temperature: %.2f %c\n", result, to);

    
    const char* category = categorize(tempC);
    printf("Temperature category: %s\n", category);
    printf("Weather advisory: %s\n", advisory(category));

    return 0;
}
