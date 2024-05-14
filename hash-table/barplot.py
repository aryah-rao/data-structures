import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

# Read the CSV file into a DataFrame
df = pd.read_csv('hash_table_slots.csv')

x = np.arange(len(df['x']))  
y = df['y']  

fig, ax = plt.subplots(figsize=(13,6))

# Create bar plot
bars = ax.bar(x=x, height=y, tick_label=df['x'])

# Axis formatting
ax.spines['top'].set_visible(False)
ax.spines['right'].set_visible(False)
ax.spines['left'].set_visible(False)
ax.spines['bottom'].set_color('#DDDDDD')
ax.tick_params(bottom=False, left=False)
ax.set_axisbelow(True)
ax.yaxis.grid(True, color='#EEEEEE')
ax.xaxis.grid(False)

# Add labels and title
ax.set_xlabel('Slot', labelpad=10, color='#333333')
ax.set_ylabel('Elements', labelpad=10, color='#333333')
ax.set_title('Distribution of Slot Usage', fontsize = 18, pad=20, color='#333333', weight='bold')

fig.tight_layout()

# Save the bar chart as an image file (e.g., PNG)
plt.savefig('barplot.png')
plt.show()


