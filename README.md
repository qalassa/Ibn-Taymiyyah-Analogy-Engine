# Ibn-Taymiyyah-Analogy-Engine
This program is an analogy engine designed to determine if a drink is prohibited based on its attributes and by comparing it to a database of known drinks. The decision is made using analogical reasoning, inspired by Ibn Taymiyyah's critique of Aristotelian logic.
-----------------------------------------------------------------------------------------
Components:

1. DrinkCase Struct:

Represents a drink with attributes like name, flavor, color, origin, alcohol content, and its intoxicating and prohibited properties.

2. AttributeWeights Struct:

Represents the importance (weight) of each attribute. For instance, alcohol content might be deemed more significant than color in determining if a drink is prohibited.

3. AnalogyEngine Class:

Contains the core logic of the program.
Maintains a database of known drinks.
Uses a similarity measure to compare a new drink to the drinks in the database. The similarity is calculated based on the attributes of the drinks and the weights assigned to each attribute.
Determines if a drink is prohibited by considering multiple similar drinks from the database and making a decision based on a majority.

4. Main Function:

Allows the user to define weights for different attributes, making the analogy engine adaptable to different perspectives.
Collects information about a new drink from the user.
Uses the analogy engine to determine if the new drink is prohibited and then displays the result.

Working:

1. The user is prompted to assign weights to different attributes of a drink. These weights signify the importance of each attribute in determining the prohibition status of a drink.
2. The user then provides details about a new drink, including its name, flavor, color, origin, and alcohol content.
3. The program considers a drink intoxicating if its alcohol content is more than 0.5%.
4. The analogy engine compares the new drink to a database of known drinks. It calculates a similarity score for each known drink based on the attributes and the user-defined weights.
5. The program considers drinks that have a similarity score within 80% of the highest score.
6. If more than half of these similar drinks are prohibited, the new drink is deemed prohibited; otherwise, it's not.
7. The program then displays whether the new drink is prohibited or not.
