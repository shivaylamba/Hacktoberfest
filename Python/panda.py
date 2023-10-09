import pandas as pd

# Creating a DataFrame from a dictionary
data = {'Name': ['Alice', 'Bob', 'Charlie'],
        'Age': [25, 30, 35]}
df = pd.DataFrame(data)


# Basic Statistics:
df['Age'].mean()   # Calculate the mean of the 'Age' column
df['Age'].median() # Calculate the median of the 'Age' column

# Sorting Data:
sorted_df = df.sort_values(by='Age', ascending=False)
