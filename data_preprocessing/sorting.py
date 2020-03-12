#%%
import numpy as np
import pandas as pd

#%%
data = pd.read_csv('../dataset/web-Google.csv', header=None, sep=',')
print(data)

# %%
data = data.sort_values(data.columns[0])
print(data)

# %%
data.to_csv('../dataset/new.csv', index=False)

# %%
