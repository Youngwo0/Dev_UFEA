import pickle
import pandas as pd

data_pkl = '/Users/leeyoungwoo/Desktop/Dev/Database/weekly_price_df.pkl'

data = pd.read_pickle(data_pkl)

file_name = "weekly_price_df"

data.to_csv(file_name+".csv")
