.PHONY: clean All

All:
	@echo "----------Building project:[ Picareta - Debug ]----------"
	@cd "Picareta" && $(MAKE) -f  "Picareta.mk"
clean:
	@echo "----------Cleaning project:[ Picareta - Debug ]----------"
	@cd "Picareta" && $(MAKE) -f  "Picareta.mk" clean
