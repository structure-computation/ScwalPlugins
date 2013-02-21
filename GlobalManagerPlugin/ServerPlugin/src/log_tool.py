import time
import datetime
import shlex, subprocess
import httplib, urllib
import sys, os
import zipfile

def main():
    if len(sys.argv) != 5:
        print "pas assez d'arguments"
        return

    # recuperation des donnees---------------------------------------------------------------------    
    model_id = int(sys.argv[1])
    app_type = sys.argv[2]
    app_time = int(sys.argv[3])
    app_cpu  = int(sys.argv[4])
    
    print model_id #affiche arg1
    print app_type #affiche arg2
    print app_time #affiche arg3
    print app_cpu  #affiche arg3
    
    #mise de in_process dans le log et dans la bdd--------------------------------------------------
    #connection au site web pour la mise a jour des info de fin de calcul -------------------------
    params = urllib.urlencode({'sc_model_id': model_id, 'app_type': app_type, 'app_time': app_time, 'app_cpu': app_cpu})
    headers = {"Content-type": "application/x-www-form-urlencoded", "Accept": "text/plain"}

    #conn = httplib.HTTPConnection("dev.structure-computation.com")
    #conn = httplib.HTTPConnection("computation-lab.local")
    conn = httplib.HTTPConnection("localhost:3000")
    conn.request("POST", "/log_tools/use_scwal_tool", params, headers)
    response = conn.getresponse()
    print response.status, response.reason
    data = response.read()
    conn.close()

main()
