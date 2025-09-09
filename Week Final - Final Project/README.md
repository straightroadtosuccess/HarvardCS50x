# GOAL PROGRESS TRACKER
#### Video Demo: <https://www.youtube.com/watch?v=fhtPRumOJRk>
#### Description:

This project is a **command-line goal tracker** I built for my CS50P final project. It lets you create and track personal goals over time. You can add new goals, log progress with dates, and see how far you’ve come with simple ASCII progress bars. It also keeps a full history of progress logs, calculates momentum to show your average improvement, and saves everything so your data is persistent between sessions. The main idea was to have something simple, lightweight, and easy to use that gives clear feedback on progress.

### Features

- **Add a goal**: Create a new goal with a name and initial progress.
- **Log progress**: Update existing goals with new progress entries and dates.
- **Visual progress bars**: See your progress with a quick ASCII bar.
- **Show goal logs**: Review all logged progress for each goal, including date, amount, and percentage completed.
- **Show momentum**: Check your average progress per log to track trends over time.
- **Remove a goal**: Delete goals you’ve completed or no longer want to track.
- **Persistent storage**: All goals and logs are saved to `goals.json` so nothing is lost between sessions.

### Files and Code Overview

- `project.py`: Main program file with everything in one place.
  - `Goal.__init__()`: Sets up a new goal with name and current progress.
  - `add_progress()`: Adds a new progress entry and updates current progress.
  - `progress_bar()`: Creates a simple ASCII progress bar.
  - `progress_percent()`: Calculates the current percentage of completion.
  - `show_logs()`: Shows all logs with bars and percentages.
  - `show_momentum()`: Calculates average improvement per log entry.
  - `save_goals()` and `load_goals()`: Handle saving and loading goals from JSON.
  - `main()`: Runs the menu loop and calls the corresponding functions.

### Design Decisions

I chose **JSON** (`goals.json`) for storage because it’s simple, readable, and easy to work with. Each goal is stored as a dictionary with name, current progress and log history.

The program is meant to be simple and user-friendly. The menu shows all the options, and each choice calls the matching function. Progress bars give instant visual feedback, and logs keep a history of everything so you can see how you’ve improved over time.

### Challenges

Handling empty or corrupted JSON files was tricky at first. I added error handling so the program starts fresh if the file is missing or broken. Removing goals without breaking the list was another thing I had to handle carefully.

### Possible Improvements

I could add exporting to csv feature to allow cross platform useability. Reports could be another good feature.
