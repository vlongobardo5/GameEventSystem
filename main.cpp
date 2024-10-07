#include <iostream>
#include <string>
#include <vector>

using namespace std;



// Player class (Observer)
class Player {
private:
    std::string name;

public:
    Player(const std::string& name) : name(name) {}

    // Method to notify the player of an event
    void notify(const std::string& event) {
        std::cout << name << " received event: " << event << std::endl;
    }
};

// Singleton GameEngine class
class GameEngine {
private:
    // Static instance of the singleton
    static GameEngine* instance;

    // Private constructor to prevent instantiation
    GameEngine() {}

    // List of players to notify when an event is triggered
    std::vector<Player*> players;

public:
    // Method to provide global access to the singleton instance
    static GameEngine* getInstance() {
        if (instance == nullptr) {
            instance = new GameEngine();
        }
        return instance;
    }

    // Method to register a player
    void registerPlayer(Player* player) {
        players.push_back(player);
    }

    // Method to trigger an event and notify all registered players
    void triggerEvent(const std::string& event) {
        std::cout << "[GameEngine] Event Triggered: " << event << std::endl;
        for (Player* player : players) {
            player->notify(event);
        }
    }

    // Method to simulate a player action
    void playerAction(const std::string& playerName, const std::string& action) {
        std::cout << "[GameEngine] " << playerName << " " << action << std::endl;
    }
};

// Initialize the static instance to nullptr
GameEngine* GameEngine::instance = nullptr;

int main() {
    GameEngine* engine = GameEngine::getInstance();

    // Trigger game events
    engine->triggerEvent("Enemy appeared!");
    engine->triggerEvent("Treasure found!");

    // Simulate player actions
    engine->playerAction("Player1", "attacks the enemy.");
    engine->playerAction("Player2", "collects the treasure.");

    // Another game event and player action
    engine->triggerEvent("Player leveled up!");
    engine->playerAction("Player1", "casts a spell.");

    return 0;
}

/**
 * Expected Output:
 *
 * [GameEngine] Event Triggered: Enemy appeared!
 * [GameEngine] Event Triggered: Treasure found!
 * [GameEngine] Player1 attacks the enemy.
 * [GameEngine] Player2 collects the treasure.
 * [GameEngine] Event Triggered: Player leveled up!
 * [GameEngine] Player1 casts a spell.
 */
