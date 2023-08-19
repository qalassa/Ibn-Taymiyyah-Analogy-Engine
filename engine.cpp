#include <iostream>
#include <vector>
#include <string>
#include <cmath>

struct DrinkCase {
    std::string name;
    std::string flavor;
    std::string color;
    std::string origin;
    double alcoholContent;
    bool isIntoxicating;
    bool isProhibited;
};

struct AttributeWeights {
    double flavorWeight = 1.0;
    double colorWeight = 1.0;
    double originWeight = 1.0;
    double alcoholContentWeight = 2.0;
};

class AnalogyEngine {
private:
    std::vector<DrinkCase> database;
    AttributeWeights weights;

    // Calculate similarity between two cases
    double calculateSimilarity(const DrinkCase& a, const DrinkCase& b) {
        double score = 0.0;

        if (a.flavor == b.flavor) score += weights.flavorWeight;
        if (a.color == b.color) score += weights.colorWeight;
        if (a.origin == b.origin) score += weights.originWeight;
        score += weights.alcoholContentWeight * (1.0 - std::abs(a.alcoholContent - b.alcoholContent));

        return score;
    }

public:
    AnalogyEngine(const AttributeWeights& w) : weights(w) {
        // Initialize with known cases
        database.push_back({"grape wine", "sweet", "red", "Italy", 12.0, true, true});
        database.push_back({"apple cider", "sweet", "golden", "USA", 0.0, false, false});
        // Add more cases as needed
    }

    bool isDrinkProhibited(const DrinkCase& newDrink) {
        double maxSimilarity = -1.0;
        int similarCount = 0;
        int prohibitedCount = 0;

        for (const DrinkCase& existingDrink : database) {
            double similarity = calculateSimilarity(newDrink, existingDrink);
            if (similarity > maxSimilarity * 0.8) {  // considering drinks with similarity within 80% of the max
                similarCount++;
                if (existingDrink.isProhibited) {
                    prohibitedCount++;
                }
            }
            if (similarity > maxSimilarity) {
                maxSimilarity = similarity;
            }
        }

        // If more than half of the similar drinks are prohibited, then the new drink is prohibited
        return prohibitedCount > similarCount / 2;
    }
};

int main() {
    AttributeWeights userWeights;
    std::cout << "Enter weight for flavor (default 1.0): ";
    std::cin >> userWeights.flavorWeight;

    std::cout << "Enter weight for color (default 1.0): ";
    std::cin >> userWeights.colorWeight;

    std::cout << "Enter weight for origin (default 1.0): ";
    std::cin >> userWeights.originWeight;

    std::cout << "Enter weight for alcohol content (default 2.0): ";
    std::cin >> userWeights.alcoholContentWeight;

    AnalogyEngine engine(userWeights);

    DrinkCase inputDrink;
    std::cout << "Enter the name of the drink: ";
    std::cin >> inputDrink.name;

    std::cout << "Enter the flavor of the drink: ";
    std::cin >> inputDrink.flavor;

    std::cout << "Enter the color of the drink: ";
    std::cin >> inputDrink.color;

    std::cout << "Enter the origin of the drink: ";
    std::cin >> inputDrink.origin;

    std::cout << "Enter the alcohol content of the drink (in percentage): ";
    std::cin >> inputDrink.alcoholContent;

    inputDrink.isIntoxicating = inputDrink.alcoholContent > 0.5;  // considering a drink intoxicating if alcohol content is more than 0.5%

    bool isProhibited = engine.isDrinkProhibited(inputDrink);

    if (isProhibited) {
        std::cout << inputDrink.name << " is prohibited." << std::endl;
    } else {
        std::cout << inputDrink.name << " is not prohibited." << std::endl;
    }

    return 0;
}
