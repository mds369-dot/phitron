from django.shortcuts import render
from django.http import HttpResponse
# Create your views here.

def home(request):
    return HttpResponse("WelCome to the Task Management System!")
def contact(request):
    return HttpResponse("<h1 style='color: red' ><i>This is contact page</i></h1>")

def show_task(request):
    return HttpResponse('This is oru taks Page!')