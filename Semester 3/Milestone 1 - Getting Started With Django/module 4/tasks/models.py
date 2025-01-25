from django.db import models

# Create your models here.
class task(models.Model):
   title = models.CharField(max_length=250)
   description = models.TextField()
   due_date = models.DateField()
   is_completed = models.BooleanField(default=False)
   created_at = models.DateTimeField(auto_now_add=True)
   updated_at = models.DateTimeField(auto_now=True)


   # One to One
   # Many to One
   # Many to Many