# Todo List CLI App Assignment *Requirements below.
## not finished
1. **weather integration:**
2. **closer output to requirement**
- `Example Output:`
```shell
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Todo List version: 0.5

Loading...

List loaded successfully.

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Enter a command ('help' for commands, 'quit' to exit)
Command: show

1  : Do the laundry           : Very dirty                          By: 03-08-2023 | Is: High     | Is: Not Started
2  : make the bed             : -                                   By: 08-08-2023 | Is: Low      | Is: Not Started
3  : Make dinner              : fish and chips                      By: 15-08-2023 | Is: Medium   | Is: Not Started
4  : feed the cat             : from the fish and chips             By: 02-08-2023 | Is: Low      | Is: Not Started
5  : clean the bathroom       : may god help you                    By: 06-08-2023 | Is: High     | Is: In Progress
6  : Buy groceries            : its on a list on the fridge         By: 01-08-2023 | Is: Medium   | Is: Not Started
7  : Claim free games         : On EpicGames                        By: 20-08-2023 | Is: High     | Is: Done
8  : Pay electricity bill     : Using banking app                   By: 10-08-2023 | Is: High     | Is: Not Started
9  : Make Coffee              : With milk                           By: 31-07-2023 | Is: Medium   | Is: Not Started
10 : Eat healthy              : in fridge                           By: 30-07-2023 | Is: High     | Is: Not Started

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Command: additem

You have entered an invalid command, please use "help" command to guide you!

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Command: help

Note that commands & priority are case sensitive


Commands:

add "Title" "Description" "Due date: dd-mm-yyyy" "Priority, low/medium/high"

edit "Item id" "Title" "Description" "Due date: dd-mm-yyyy" "Priority: low/medium/high"

delete "Item id"

progress "Item id" "not started/in progress/done"

show

sort "addition/priority/progress"

filter priority "priority high/priority medium/priority low" or progress "not started/in progress/done"

save

quit

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Command: add "pick up sister" "she's at her school" 10-8-2023 high


Item added successfully.

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Command: show

1  : Do the laundry           : Very dirty                          By: 03-08-2023 | Is: High     | Is: Not Started
2  : make the bed             : -                                   By: 08-08-2023 | Is: Low      | Is: Not Started
3  : Make dinner              : fish and chips                      By: 15-08-2023 | Is: Medium   | Is: Not Started
4  : feed the cat             : from the fish and chips             By: 02-08-2023 | Is: Low      | Is: Not Started
5  : clean the bathroom       : may god help you                    By: 06-08-2023 | Is: High     | Is: In Progress
6  : Buy groceries            : its on a list on the fridge         By: 01-08-2023 | Is: Medium   | Is: Not Started
7  : Claim free games         : On EpicGames                        By: 20-08-2023 | Is: High     | Is: Done
8  : Pay electricity bill     : Using banking app                   By: 10-08-2023 | Is: High     | Is: Not Started
9  : Make Coffee              : With milk                           By: 31-07-2023 | Is: Medium   | Is: Not Started
10 : Eat healthy              : in fridge                           By: 30-07-2023 | Is: High     | Is: Not Started
11 : pick up sister           : she's at her school                 By: 10-08-2023 | Is: High     | Is: Not Started

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Command: progress 1 done

progress successfully set to:  done

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Command: show

1  : Do the laundry           : Very dirty                          By: 03-08-2023 | Is: High     | Is: Done
2  : make the bed             : -                                   By: 08-08-2023 | Is: Low      | Is: Not Started
3  : Make dinner              : fish and chips                      By: 15-08-2023 | Is: Medium   | Is: Not Started
4  : feed the cat             : from the fish and chips             By: 02-08-2023 | Is: Low      | Is: Not Started
5  : clean the bathroom       : may god help you                    By: 06-08-2023 | Is: High     | Is: In Progress
6  : Buy groceries            : its on a list on the fridge         By: 01-08-2023 | Is: Medium   | Is: Not Started
7  : Claim free games         : On EpicGames                        By: 20-08-2023 | Is: High     | Is: Done
8  : Pay electricity bill     : Using banking app                   By: 10-08-2023 | Is: High     | Is: Not Started
9  : Make Coffee              : With milk                           By: 31-07-2023 | Is: Medium   | Is: Not Started
10 : Eat healthy              : in fridge                           By: 30-07-2023 | Is: High     | Is: Not Started
11 : pick up sister           : she's at her school                 By: 10-08-2023 | Is: High     | Is: Not Started

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Command: quit

Do you want to save before quitting(y/n)/(any other key to cancel): y
saving...
quitting...
Press Enter to exit...
```

# Todo List Console App Requirements

1. **Todo Item Creation:** Users should be able to add todo items. Each item should include a title and optional description, due date, and priority.
2. **Todo Item Modification:** Users should be able to edit the details of a todo item after it has been created.
3. **Todo Item Deletion:** Users should have the ability to delete a todo item.
4. **Listing Todo Items:** The app should provide users with a way to see all their todo items. This should include:
    - A way to sort by due date, creation date, priority, and status.
    - A way to filter by status and priority.
5. **Error Handling:** The app should handle potential errors gracefully and provide users with meaningful error messages.
6. **Weather Reminders:** The application should have a feature that allows the user to request weather forecasts which can help them plan their upcoming tasks. This feature will utilize a weather API to fetch forecast data based on the user's provided location.
7. **Exit:** Users should be able to exit the application safely without losing data.

## CLI Commands

- `additem <title> <description> <duedate> <priority>`: Adds a new item.
- `edititem <itemid> <newtitle> <newdescription> <newduedate> <newpriority>`: Edits the item with the given ID.
- `deleteitem <itemid>`: Deletes the item with the given ID.
- `showitems`: Shows all items.
- `sortby <parameter>`: Sorts items by the given parameter (due date, creation date, priority, or status).
- `filterby <parameter>`: Filters items by the given parameter (status or priority).
- `markasdone <itemid>`: Marks the item with the given ID as completed.
- `weather <location>`: Fetches and displays the weather forecast for the next 24 hours for the given location.
- `exit`: Safely closes the application and saves all data.

## Example Usage

```shell
# Add an item
> additem "Finish report" "For the Monday meeting" 2023-07-25 high
Item 'Finish report' has been successfully added.

> additem "Email John" "About project updates" 2023-07-23 medium
Item 'Email John' has been successfully added.

# Show all items
> showitems
1. Finish report - For the Monday meeting - Due: 2023-07-25 - Priority: High - Status: Not Started
2. Email John - About project updates - Due: 2023-07-23 - Priority: Medium - Status: Not Started

# Edit an item
> edititem 2 "Email John and Peter" "About project and marketing updates" 2023-07-23 high
Item 2 has been successfully updated.

> showitems
1. Finish report - For the Monday meeting - Due: 2023-07-25 - Priority: High - Status: Not Started
2. Email John and Peter - About project and marketing updates - Due: 2023-07-23 - Priority: High - Status: Not Started

# Mark an item as done
> markasdone 2
Item 2 has been marked as completed.

> showitems
1. Finish report - For the Monday meeting - Due: 2023-07-25 - Priority: High - Status: Not Started
2. Email John and Peter - About project and marketing updates - Due: 2023-07-23 - Priority: High - Status: Completed

# Get the weather forecast for San Francisco
> weather San Francisco
Fetching weather for San Francisco...
Weather forecast for San Francisco: Mostly sunny with a high of 22°C and a low of 15°C.

# Exit the application
> exit
Exiting the application. Your data has been saved.
