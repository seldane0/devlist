#include <stdio.h>
#include <endian.h>
#include <infiniband/verbs.h>

int
main(int argc, char *argv[])
{
	struct ibv_device **dev_list;
	int i, n;

	dev_list = ibv_get_device_list(&n);
	if (dev_list == NULL) {
		printf ("dev list is empty.\n");
		return -1;
	}

	/* Let's print some basic info. */
	for (i=0; i < n; i++) {
		printf ("%d: %s/%s %llx [%s,%d] [%d] [%s] [%s]\n", i,
			dev_list[i]->dev_name, dev_list[i]->name,
			(unsigned long long) be64toh(ibv_get_device_guid(dev_list[i])),
			ibv_node_type_str(dev_list[i]->node_type), dev_list[i]->node_type,
			dev_list[i]->transport_type,
			dev_list[i]->dev_path,
			dev_list[i]->ibdev_path);
	}

	/* Free the link list. */
	ibv_free_device_list(dev_list);

	return 0;
}
