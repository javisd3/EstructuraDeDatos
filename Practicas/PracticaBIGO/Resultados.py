import matplotlib.pyplot as plt

# --- ZONA DE DATOS MANUALES ---
# Eje X: Tamaño del problema (N)
N = [20.000, 483647, 147483647, 2147483647] 
# 6 cifras, 9 y 10

# --- TIEMPOS (en segundos) ---
# 1. Búsqueda Secuencial - O(n)
# Crece proporcionalmente 
T_Secuencial = [0.0010, 0.0020, 1.76]

# 2. Búsqueda Binaria - O(log n)
# Tiempos casi instantáneos y planos 
T_Binaria = [0.000002, 0.000002, 0.000005]

# 3. Ordenación Directa (Burbuja) - O(n^2)
# Crece EXPLOSIVAMENTE. Si N se dobla, el tiempo se multiplica por 4.
T_Directa = [1.0, 4.0, 25.0]

# 4. Ordenación por Mezcla (Merge Sort) - O(n log n)
# Rápido, un poco más lento que lineal pero mucho mejor que Directa
T_Mezcla = [0.0025, 0.0055, 0.0150]
# ------------------------------

# Configuración de la gráfica
plt.figure(figsize=(100, 7))

# Dibujar las 4 líneas con colores y marcadores distintos
plt.plot(N, T_Secuencial, 'o-', color='green', label='Búsqueda Secuencial O(n)')
plt.plot(N, T_Binaria,    'x-', color='blue',  label='Búsqueda Binaria O(log n)')
plt.plot(N, T_Directa,    's-', color='red',   label='Ordenación Directa O(n²)')
plt.plot(N, T_Mezcla,     '^-', color='orange',label='Ordenación Mezcla O(n log n)')

# Etiquetas
plt.title('Comparativa de Complejidad: Búsquedas y Ordenaciones')
plt.xlabel('Tamaño del Array (N)')
plt.ylabel('Tiempo (segundos)')

# Añadir rejilla y leyenda
plt.grid(True)
plt.legend()

# Mostrar la gráfica
print("Abriendo gráfica con los 4 algoritmos...")
plt.show()