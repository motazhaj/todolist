# Todo List CLI App Assignment *Requirements below.
## not finished

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
