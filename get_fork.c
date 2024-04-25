#include "shell.h"

pid_t get_fork(void)
{
  pid_t pid = -1;
  pid = vfork(); /* Utilisation de vfork() pour minimiser les problèmes potentiels de mémoire*/

  if (pid < 0) /* Erreur lors de la création du processus fils*/
  {
    perror("my_fork");
    exit(EXIT_FAILURE);
  }

  return (pid); /* Retourne l'ID du processus créé (0 pour le processus fils, PID du fils pour le processus parent)*/
}