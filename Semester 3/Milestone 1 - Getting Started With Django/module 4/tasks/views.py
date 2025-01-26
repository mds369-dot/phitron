from django.shortcuts import render
from django.http import HttpResponse
# Create your views here.

def manager_dashboard(request):
    return render(request, 'dashboard/manager-deshboard.html')
def user_dashboard(request):
    return render(request, 'dashboard/user-dashboard.html')

def test(request):
    context = {
        "names" : ["Rahul", "Rohit", "Rajesh", "Ramesh", "John"],
        "age" : [20, 21, 22, 23],
    }
    return render(request, 'test.html', context)

def create_task(request):
    return render(request, 'task_form.html')