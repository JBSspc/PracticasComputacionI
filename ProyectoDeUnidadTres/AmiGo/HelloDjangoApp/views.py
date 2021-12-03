from django.shortcuts import render

# Create your views here.

from django.http import HttpResponse
from datetime import datetime
from django.shortcuts import render   # Added for this step

def index(request):
    now = datetime.now()

    return render(
        request,
        "HelloDjangoApp/index.html",  # Relative path from the 'templates' folder to the template file
        # "index.html", # Use this code for VS 2017 15.7 and earlier
        {
            'title' : "AmiGo",
            'message' : "AmiGo",
            'content' : " on " + now.strftime("%A, %d %B, %Y at %X")
        }
    )

def biochem(request):
    return render(
        request,
        "HelloDjangoApp/biochem.html",
        {
            'title' : "Biochemestry",
        }
    )