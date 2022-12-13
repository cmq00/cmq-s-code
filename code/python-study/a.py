 21         datas = pd.DataFrame(pd.read_excel('/opt/wypython/trunk/lvlin/res.xlsx'))
 22         id_list = []
 23         for index, row in datas.iterrows():
 24             try:
 25                 id_list.append(deepcopy(int(row['id'])))
 26             except:
 27                 continue
 28 

 32 
 33         for i in range(start_id, end_id + 1):
 34             if i in id_list:
					continue
	

