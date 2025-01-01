# import pyautogui
# import time

# def draw_pyramid(rows):
#     time.sleep(3)

#     for i in range(1, rows + 1):
#         pyautogui.typewrite('#' * i)

        

# rows = int(input("Enter the number of rows: "))
# draw_pyramid(rows)
# Function to print a half pyramid pattern
import pyautogui
import time

def half_pyramid(n):
    # Adding a delay to allow you to focus on a text editor or terminal
    time.sleep(2)  

    for i in range(1, n + 1):
        for j in range(1, i + 1):
            pyautogui.write("* ")
        pyautogui.write("\n")  # Simulate pressing the Enter key after each line

# Example: Print a half pyramid with 5 rows
n = 5
half_pyramid(n)
