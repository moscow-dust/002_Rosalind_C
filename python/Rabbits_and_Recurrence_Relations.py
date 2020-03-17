import time
import plotly
import plotly.graph_objs as go
def sequence(months, pair):
    if months == 0:
        return 0
    elif months == 1:
        return 1
    else:
        return(sequence((months-1), pair)+(sequence((months-2), pair)*pair))
pair = 3
months = 2
print(sequence(months,pair))
#count time of function execution  
def count_time(f, arg1,arg2, n = 100):
    t = float("inf")
    for i in range(n):
        t1_start = time.perf_counter()
        f(arg1,arg2)
        t1_stop = time.perf_counter()
        t = min(t,t1_stop-t1_start)
    return t
#draw scatter plot 3D
x = [i for i in range(1,21)]
y = [j for j in range(1,21)]
z = []
print(x,y)
for i in zip(x,y):
    z.append(count_time(sequence,i[0], i[1]))
fig = go.Scatter3d(x=x,y=y,z=z)
mylayout = go.Layout(scene=dict(xaxis=dict(title="months"),
                                yaxis= dict(title="pairs"),
                                zaxis=dict(title="time")))
plotly.offline.plot({"data": [fig],
                     "layout": mylayout},
                     auto_open=True,
                     filename=("graf.html"))


