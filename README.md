# My Zork

**My Zork** is a C++ text-based adventure game inspired by the classic *Zork*. This project showcases my C++ game programming skills by implementing an interactive, exploration-based experience with inventory mechanics and potential combat elements.

## 🏰 Game Overview

In **My Zork**, you play as a character living in the woods with your father. One day, he sends you on a mission to warn the village guard about an incoming Orc horde. Your journey will take you through a series of connected rooms, where you'll interact with objects, solve puzzles, and possibly encounter enemies.

## 🎯 Objectives

### ✅ Core Features

- [x] Three connected rooms
- [x] Five connected rooms
- [x] Interactive items that can be picked up and dropped
- [x] Ability to drop items
- [x] Items can be placed inside other items

### 🔥 Extra Features (Planned)

- [x] Key that allows to cross a path
- [x] NPC dialog interactions
- [x] Creatures that walk arround
- [x] NPC situational and changing dialogues
- [ ] Enemy encounters
- [ ] A visual map (looking like the original *Zork*)
- [ ] An exit puzzle

## 🎮 How to Play

1. **Download** the release folder.
2. **Run** `MyZork.exe`.
3. **Explore** the world, interact with objects, and complete your quest.
4. **Have fun!**

## 🕹 Implemented Commands

- `HELP` – Displays the list of available commands.
- `GO [NORTH | SOUTH | EAST | WEST]` – Moves in the specified direction if possible.
- `LOOK` – Describes the surroundings and objects in the current location.
- `TAKE [item]` – Pick up an item if possible and add to the inventory.
- `DROP [item]` – Drop an item in the current location.
- `INVENTORY` - List all items that player have in the inventory.
- `USE [item] ON [path]` - Use something to allow going across a path.
- `TALK [creature]` - Short dialogue with some creature.
- `TAKE [item] FROM [item]` - Pick up an item that is inside of another item if possible and add to the inventory.
- `DROP [item] TO [item]` - Drop an item inside of another item if it is possible.

## 🚧 Features in Development

- `ATTACK [creature] WITH [item]` – Attack an enemy using an item.

## 🔎 Special Notes

- All commands are **case-insensitive**, meaning you can use uppercase or lowercase letters interchangeably.
- The game follows a **text-based input system**, requiring players to type commands manually.

## 👤 Author

**Héctor Núñez Carpio**

## 📜 License

This project is licensed under the **MIT License**. See [LICENSE.txt](./License.txt) for details.